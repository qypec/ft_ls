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
		matr = matrix_sort(head, matr, flags); // функция будет в зависимости от сортировочного флага сортировать матрицу
		print(head, matr, flags);
	}
	else
	{
		matr = argv_to_matrix((const char **)matr, head, flags); /* заполняет матрицу из argv, включая несуществующие файлы */
		head = struct_filenames(&head, (const char **)matr, "./", flags);
		// ft_putmatrix(matr);
		matr = matrix_sort(head, matr, flags);
		while (matr[i] != NULL) /* вывод файлов из argv, если не директория */
		{
			if ((tmp = find_list(&head, matr[i])) == NULL) /* пропускает несуществующие файлы */
			{
				i++;
				continue ;
			}
			if (tmp->type == T_FILE)
				ft_putendl(matr[i]);
			i++;
		}
		ft_putchar('\n');
		i = 0;
		while (matr[i] != NULL)
		{
			if ((tmp = find_list(&head, matr[i])) == NULL) // функция по имени из matrix находит нужный лист и возвращает указатель на него. Это сделано для того, чтобы не сортировать односвязный список
			{
				i++;		/* такое возможно если в аргументы подали несуществующий файл */
				continue ;
			}
			if (tmp->type == T_DIR && ft_strcmp(tmp->name, "..") != 0 && ft_strcmp(tmp->name, ".") != 0) // если лист - папка 
			{
				print_path(matr[i]);
				new_path = get_path(tmp->name, tmp->path);
				ft_matrixfree(&matr);
				matr = get_rootnames(&matr, new_path, flags);
				//free head
				head = struct_filenames(&head, (const char **)matr, new_path, flags);
				matr = matrix_sort(head, matr, flags); 
				ft_strdel(&new_path);
				ft_putmatrix(matr);
			}
			// очистка tmp
			i++;
		}
	}
	// очистить matr и head
}
