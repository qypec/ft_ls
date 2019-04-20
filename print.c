/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 16:42:07 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/20 16:21:05 by wconnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_l(t_file *tmp)
{
	char	*str1;
	char	*str2;

	ft_putstr(tmp->chmod);
	ft_putstr("   ");
	str2 = ft_itoa(tmp->numlink);
	ft_putstr(str2);
	ft_strdel(&str2);
	ft_putstr(" ");
	ft_putstr(tmp->username);
	ft_putstr("  ");
	ft_putstr(tmp->year); // print year
	ft_putstr("  ");
	str1 = ft_itoa(tmp->size);
	ft_putstr(str1);
	ft_strdel(&str1);
	ft_putstr(" ");
	ft_putstr(tmp->date); // print date
	ft_putstr(" ");
	ft_putendl(tmp->name);
}

void		print_dir(char *path, t_flags *flags)
{
	t_file *head;

	head = NULL;
	head = get_rootnames(&head, path, flags);
	sort_list(&head, flags);
	print_struct(&head, flags);
	structfree(&head);
}

void		print_path(const char *path)
{
	int i;
	int	len;

	i = 0;
	if (path[0] == '.' && path[1] == '/' && path[2] == '\0')
		return ;
	if (path[0] == '.' && path[1] == '/')
		i += 2;
	len = ft_strlen(path);
	if (path[len - 1] == '/')
	{
		while (i != len - 1) /* убраем последнй слеш */
		{
			ft_putchar(path[i]);
			i++;
		}
	}
	else
	{
		while (path[i] != '\0')
		{
			ft_putchar(path[i]);
			i++;
		}
	}
	ft_putchar(':');
	ft_putchar('\n');
}

void		print_struct(t_file **head, t_flags *flags)
{
	t_file	*tmp;
	char	*no_leaks;

	tmp = *head;
	if (*head == NULL)
	{
		ft_putchar('\n');
		return ;
	}
	if (flags->l == 1)
	{
		ft_putstr("\ntotal ");
		no_leaks = ft_itoa(tmp->totalsize);
		ft_putendl(no_leaks);
		ft_strdel(&no_leaks);
	}
	while (tmp != NULL)
	{
		if (flags->l == 1)
			print_l(tmp);
		else
			ft_putendl(tmp->name);
		tmp = tmp->next;
	}
	ft_putchar('\n');
}

void		print_without_dir(t_file **head, t_flags *flags)
{
	t_file	*tmp;

	tmp = *head;
	if (flags->l == 1 && tmp->type != T_DIR)
	{
		ft_putchar('\n');
		ft_putstr("total ");
		ft_putendl(ft_itoa(tmp->totalsize));
	}
	while (tmp != NULL)
	{
		if (tmp->type != T_DIR)
		{
			if (flags->l == 1)
				print_l(tmp);
			else
				ft_putendl(tmp->name);
		}
		tmp = tmp->next;
	}
	ft_putchar('\n');
}
