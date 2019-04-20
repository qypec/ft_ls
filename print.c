/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 16:42:07 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/20 18:39:42 by wconnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_dir(char *path, t_flags *flags)
{
	t_file *head;

	head = NULL;
	head = get_rootnames(&head, path, flags);
	sort_list(&head, flags);
	print_struct(&head, flags, path);
	structfree(&head);
}

void		print_path(const char *path)
{
	int		i;
	int		len;

	i = 0;
	if (path[0] == '.' && path[1] == '/' && path[2] == '\0')
		return ;
	if (path[0] == '.' && path[1] == '/')
		i += 2;
	len = ft_strlen(path);
	if (path[len - 1] == '/')
	{
		while (i != len - 1)
		{
			ft_putchar(path[i++]);
		}
	}
	else
	{
		while (path[i] != '\0')
		{
			ft_putchar(path[i++]);
		}
	}
	ft_putchar(':');
	ft_putchar('\n');
}

void		print_struct(t_file **head, t_flags *flags, char *path)
{
	t_file	*tmp;

	tmp = *head;
	if (*head == NULL)
	{
		ft_putchar('\n');
		return ;
	}
	if (flags->l == 1)
		print_l(head, path, flags);
	else
	{
		while (tmp != NULL)
		{
			ft_putendl(tmp->name);
			tmp = tmp->next;
		}
	}
	ft_putchar('\n');
}

void		print_without_dir(t_file **head, t_flags *flags)
{
	t_file	*tmp;

	tmp = *head;
	while (tmp != NULL)
	{
		if (tmp->type != T_DIR)
			ft_putendl(tmp->name);
		tmp = tmp->next;
	}
	ft_putchar('\n');
}
