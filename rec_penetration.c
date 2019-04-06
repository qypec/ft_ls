/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_penetration.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:13:08 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/06 15:47:22 by yquaro           ###   ########.fr       */
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

int		rec_penetration(char *path, t_flags *flags) // рекурсия
{
		t_file		*head;
		char		**matr;
		int			i;

		i = 0;
		head = NULL;
		matr = get_rootnames(matr, path); // заполняет матрицу именами, которые вытаскиваются по пути
		head = struct_filenames(&head, matr, path);
		matr = matrix_sort(head, &matr, flags);
		print(head, matr, flags);
		while (matr[i] != NULL)
		{
			tmp = find_list(head, matr[i]); // функция по имени из matrix находит нужный лист и возвращает указатель на него. Это сделано для того, чтобы не сортировать односвязный список
			if (tmp->type == T_DIR) // если лист - папка 
			{
				new_path = get_path(tmp->name, tmp->path); 	// когда заходим в рекурсию, меняется директория. Чтобы работал stat, соединяем путь и имя папки, в которую заходим ( ./ + libft + / = ./libft/ )
				rec_penetration(new_path, flags);
			}
			i++;
		}
}

int		init(t_file *head, char **matr, t_flags *flags) // функция, из которой мы вызываем рекурсию
{
	t_file	*tmp;
	char	*new_path;
	int		i;

	i = 0;
	tmp = head;
	if (matr == NULL) // если передали не argv
	{
		matr = get_rootnames(matr, "./");
		matr = matrix_sort(head, &matr, flags); // функция будет в зависимости от сортировочного флага сортировать матрицу
	}
	print(head, matr, flags);
	while (matr[i] && is_it_flag(matr[i]))
		i++;
	while (matr[i] != NULL)
	{
		tmp = find_list(head, matr[i]); // функция по имени из matrix находит нужный лист и возвращает указатель на него. Это сделано для того, чтобы не сортировать односвязный список
		if (tmp->type == T_DIR) // если лист - папка 
		{
			new_path = get_path(tmp->name, tmp->path); 	// когда заходим в рекурсию, меняется директория. Чтобы работал stat, соединяем путь и имя папки, в которую заходим ( ./ + libft + / = ./libft/ )
			rec_penetration(new_path, flags);
		}
		i++;
	}
}