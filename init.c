/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 09:28:02 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/11 20:25:25 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		init(t_file *head, char **matr, t_flags *flags)
{
	t_file	*tmp;
	char	*new_path;
	int 	i;

	i = 0;
	matr = argv_to_matrix((const char **)matr, head, flags); /* заполняет матрицу из argv, включая несуществующие файлы */
	head = struct_filenames(&head, (const char **)matr, "./", flags);
	// ft_putmatrix(matr);
	matr = matrix_sort(head, matr, flags);
	print_without_dir(head, (const char **)matr);
	
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
			print_dir(new_path, flags);
			ft_strdel(&new_path);
		}
		i++;		
	}
	ft_matrixfree(&matr);
	structfree(&head);
}
