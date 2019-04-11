/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 16:42:07 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/11 19:13:04 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_dir(char *path, t_flags *flags)
{
	ft_putendl("hee2l\n"); 
	t_file	*head;
	char	**matr;
			
	matr = get_rootnames(&matr, path, flags);
	head = struct_filenames(&head, (const char **)matr, path, flags);
	matr = matrix_sort(head, matr, flags);
	ft_putendl("heel\n"); 
	ft_putmatrix(matr);
	//free head
	ft_matrixfree(&matr);
}

void		print_path(const char *path)
{
	int i;
	int	len;

	i = 0;
	len = 0;
	ft_putchar('\n');
	if (path[0] == '.' && path[1] == '/')
		i += 2;
	len = ft_strlen(path);
	if (path[len - 1] == '/')
	{
		while (i != len - 1) /* убраем последнй слеш */
		{
			ft_putchar(path[i]);
			i++;
		}
	}
	else
	{
		while (path[i] != '\0')
		{
			ft_putchar(path[i]);
			i++;
		}
	}
	ft_putchar(':');
	ft_putchar('\n');
}

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
		if (tmp->type != T_DIR) // если лист - не директория 
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