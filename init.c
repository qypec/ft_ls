/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wconnell <wconnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 09:28:02 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/10 21:45:56 by wconnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_dir(char *path, t_flags *flags)
{
	t_file *head;

	head = NULL;
	head = get_rootnames(&head, path, flags);
	//sort
	print_struct(&head);
	//очистка

}

void		init(t_file *head, char **argv, t_flags *flags)
{
	t_file	*tmp;
	char	*new_path;
	int 	i;

	i = 0;
	head = struct_filenames(&head, (const char **)argv, "./", flags);
	// matr = matrix_sort(head, matr, flags);
	print_without_dir(&head); /* функция печатает все файлы кроме директорий */

	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->type == T_DIR && ft_strcmp(tmp->name, "..") != 0 && ft_strcmp(tmp->name, ".") != 0)
		{
			print_path(tmp->name);
			new_path = get_path(tmp->name, tmp->path);
			print_dir(new_path, flags);
			ft_strdel(&new_path);
		}
		tmp = tmp->next;
	}
	// очистить head
}
