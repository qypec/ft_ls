/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_total.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 20:29:13 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/20 19:25:14 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*calculate_total(t_file **head)
{
	t_file	*tmp;
	int		total;

	tmp = *head;
	total = 0;
	while (tmp != NULL)
	{
		total += tmp->blocks;
		tmp = tmp->next;
	}
	return (ft_itoa(total));
}

void	print_total(t_file **head)
{
	char *total;

	total = calculate_total(head);
	ft_putstr("total ");
	ft_putendl(total);
	ft_strdel(&total);
}

void	content_cpy(t_file *src, t_file *tmp)
{
	tmp->name = src->name;
	tmp->path = src->path;
	tmp->type = src->type;
	tmp->modif = src->modif;
	tmp->last_access = src->last_access;
	tmp->date = src->date;
	tmp->username = src->username;
	tmp->size = src->size;
	tmp->groupname = src->groupname;
	tmp->numlink = src->numlink;
	tmp->chmod = src->chmod;
	tmp->totalsize = src->totalsize;
}
