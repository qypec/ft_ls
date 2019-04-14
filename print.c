/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 16:42:07 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/13 21:28:49 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_l(t_file **head)
{
	t_file *tmp;

	tmp = *head;
	ft_putendl("total");
	while (tmp != NULL)
	{
		ft_putstr(tmp->chmod);
		ft_putstr("   ");
		ft_putstr(ft_itoa(tmp->numlink)); // bla
		ft_putstr(" ");
		ft_putstr(tmp->username);
		ft_putstr("  ");
		ft_putstr(tmp->year); // print year
		ft_putstr("  ");
		ft_putstr(ft_itoa(tmp->size));
		ft_putstr(" ");
		ft_putstr(tmp->date); // print date
		ft_putstr(" ");
		ft_putendl(tmp->name);
		tmp = tmp->next;
	}
}

void		print_dir(char *path, t_flags *flags)
{
	t_file *head;

	head = NULL;
	head = get_rootnames(&head, path, flags);
	//sort
	sort_list(&head, flags);
	print_struct(&head, flags);
	structfree(&head);
}

void		print_path(const char *path)
{
	int i;
	int	len;

	i = 0;
	len = 0;
	ft_putchar('\n');
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

	tmp = *head;
	if (flags->l == 1)
	{
		print_l(head);
	}
	else
	{
		while (tmp != NULL)
		{
			ft_putendl(tmp->name);
	 		tmp = tmp->next;
		}
	}
}

void		print_without_dir(t_file **head, t_flags *flags)
{
	t_file	*tmp;
	int		i;

	i = 0;
	tmp = *head;
	if (flags->l == 1)
	{
		// printf("no l-flags functional\n");
		print_l(head);
	}
	else
	{
		while (tmp != NULL)
		{
			if (tmp->type != T_DIR)
				ft_putendl(tmp->name);
			tmp = tmp->next;
		}
	}
}

// void		print(t_file *head, char **matr, t_flags *flags)
// {
// 	ft_putmatrix(matr); // пока так
// }