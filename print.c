/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 16:42:07 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/09 23:26:49 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_without_dir(t_file *head, const char **matr)
{
	t_file	*tmp;
	int		i;

	i = 0;
	tmp = head;
	while (matr[i] != NULL)
	{
		if ((tmp = find_list(&head, matr[i])) == NULL) /* функция по имени из matrix находит нужный лист и возвращает указатель на него. Это сделано для того, чтобы не сортировать односвязный список */
		{
			i++;
			// очистить tmp;
			continue ;
		}
		if (tmp->type != T_DIR) // если лист - папка 
		{
			ft_putendl(matr[i]);
		}
		// очистить tmp тут
		i++;
	}
}

void		print(t_file *head, char **matr, t_flags *flags)
{
	ft_putmatrix(matr); // пока так
}