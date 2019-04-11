/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:06:26 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/11 20:28:06 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	structfree(t_file **head)
{
	if (head)
	{
		if ((*head)->next)
		{
			ft_strdel(&((*head)->name));
			ft_strdel(&((*head)->path));
			structfree(&((*head)->next));
		}
		free(*head);
		*head = NULL;
	}
}