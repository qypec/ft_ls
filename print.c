/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 16:42:07 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/12 00:04:23 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

void		print_struct(t_file **head)
{
	t_file	*tmp;

	tmp = *head;
	if (tmp == NULL)
		printf("null");
	while (tmp != NULL)
	{
		ft_putendl(tmp->name);
		tmp = tmp->next;
	}
}

void		print_without_dir(t_file **head)
{
	t_file	*tmp;
	int		i;

	i = 0;
	tmp = *head;
	while (tmp != NULL)
	{
		if (tmp->type != T_DIR)
			ft_putendl(tmp->name);
		tmp = tmp->next;
	}
}

// void		print(t_file *head, char **matr, t_flags *flags)
// {
// 	ft_putmatrix(matr); // пока так
// }