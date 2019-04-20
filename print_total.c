/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_total.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 20:29:13 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/20 18:23:04 by yquaro           ###   ########.fr       */
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