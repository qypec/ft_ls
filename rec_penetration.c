/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_penetration.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:13:08 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/04 22:03:03 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*get_path(char *name, char *path)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = ft_strjoin(path, name);
	tmp2 = ft_strjoin(tmp1, "/");
	ft_strdel(&tmp1);
	return (tmp2);
}

int		rec_penetration(char **matr, char *path, t_flags *flags) // рекурсия
{
		t_file		*head;

		head = NULL;
		head = struct_filenames(&head, matr, path);
		// очень похоже, что мы в init написали то, что нужно написать сюда 
		

}

int		init(t_file *head, t_flags *flags) // функция, из которой мы вызываем рекурсию
{
	t_file	*tmp;
	char	**matrix;
	char	*new_path;
	int		i;

	i = 0;
	tmp = head;
	matrix = matrix_fill(head); // функция заполняет матрицу на основе односвязного списка
	matrix = matrix_sort(head, &matrix, flags); // функция будет в зависимости от сортировочного флага сортировать матрицу
	while (matrix[i] != NULL)
	{
		tmp = find_list(head, matrix[i]); // функция по имени из matrix находит нужный лист и возвращает указатель на него. Это сделано для того, чтобы не сортировать односвязный список
		if (tmp->type == 2) // если лист - папка 
		{
			new_path = get_path(tmp->name, tmp->path); 	// когда заходим в рекурсию, меняется директория. Чтобы работал stat, соединяем путь и имя папки, в которую заходим ( ./ + libft + / = ./libft/ )
			rec_penetration(matr, tmp->path, flags);
		}
		i++;
	}
}