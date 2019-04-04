/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_penetration.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:13:08 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/04 20:49:04 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		rec_penetration(char **matr, t_flags *flags, char *path) // рекурсия
{
		t_file		*head;

		head = NULL;

		head = struct_filenames(&head, matr, path);
		.......

}

int		init(t_file *head, t_flags *flags) // функция, из которой мы вызываем рекурсию
{
	char	**matrix;
	char	*new_path;
	int		i;

	i = 0;
	matrix = matrix_fill(head);
	matrix = matrix_sort(head, &matrix, flags);
	while (matrix[i] != NULL)
	{
		if (is_dir())
		{
			new_path = get_path();
			rec_penetration(matr, flags, new_path);
		}
		tmp = tmp->next;
	}
}