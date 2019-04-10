/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 09:28:02 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/10 11:40:51 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		init(t_file *head, char **matr, t_flags *flags)
{
	t_file	*tmp;
	char	*new_path;
	int 	i;

	i = 0;
	if (matr == NULL) /* matr будет равен NULL только если в init передали не argv */
	{
		matr = get_rootnames(&matr, "./", flags);
		head = struct_filenames(&head, (const char **)matr, "./", flags);
		// matr = matrix_sort(head, &matr, flags); // функция будет в зависимости от сортировочного флага сортировать матрицу
		print(head, matr, flags);
	}
	else
	{
		matr = argv_to_matrix((const char **)matr, head, flags); /* заполняет матрицу из argv, включая несуществующие файлы */
		head = struct_filenames(&head, (const char **)matr, "./", flags);
		// matr = matrix_sort(head, &matr, flags);
		while (matr[i] != NULL)
		{
			if ((tmp = find_list(&head, matr[i])) == NULL) // функция по имени из matrix находит нужный лист и возвращает указатель на него. Это сделано для того, чтобы не сортировать односвязный список
			{
				i++;		/* такое возможно если в аргументы подали несуществующий файл */
				continue ;
			}
			if (tmp->type == T_DIR && ft_strcmp(tmp->name, "..") != 0 && ft_strcmp(tmp->name, ".") != 0) // если лист - папка 
			{
				new_path = get_path(tmp->name, tmp->path);
				ft_matrixfree(&matr);
				matr = get_rootnames(&matr, new_path, flags);
				ft_strdel(&new_path);
				ft_putmatrix(matr);
			}
			else
				ft_putmatrix(matr);
			i++;
		}
	}
}
