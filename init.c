/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 09:28:02 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/16 15:14:30 by wconnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			is_onlyone_arg(t_file *head)
{
	t_file	*tmp;
	int		counter;

	counter = 0;
	tmp = head;
	while (tmp != NULL)
	{
		counter++;
		tmp = tmp->next;
	}
	if (counter == 1)
		return (1);
	return (0);
}

void		init(t_file *head, char **argv, t_flags *flags)
{
	t_file	*tmp;
	char	*new_path;
	int 	i;

	i = 0;
	head = struct_filenames(&head, (const char **)argv, "./", flags);
	sort_list(&head, flags);
	print_without_dir(&head, flags); /* функция печатает все файлы кроме директорий */
	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->type == T_DIR)
		{
			if (is_onlyone_arg(head) != 1)
				print_path(tmp->name);
			new_path = get_path(tmp->name, tmp->path);
			print_dir(new_path, flags);
			ft_strdel(&new_path);
		}
		tmp = tmp->next;
	}
	structfree(&head);
}
