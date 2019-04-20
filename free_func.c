/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:03:35 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/20 16:21:05 by wconnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	structfree(t_file **head)
{
	if ((*head) != NULL)
	{
		ft_strdel(&(*head)->name);
		ft_strdel(&(*head)->path);
		ft_strdel(&(*head)->date);
		ft_strdel(&(*head)->year);
		ft_strdel(&(*head)->username);
		ft_strdel(&(*head)->chmod);
		structfree(&(*head)->next);
	}
	free(*head);
	*head = NULL;
}
