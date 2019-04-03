/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 20:18:17 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/03 20:32:25 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		filedelone(t_file **file)
{
	if (file == NULL)
		return ;
	ft_strdel(&((*file)->name));
	free(*file);
	*file = NULL;
}

t_file		*newlst(t_file	*new, const char *str)
{
	int type;

	if (!(new = malloc(sizeof(t_fig))))
		exit(1);
	new->name = ft_strdup(str);
	type = whatstype(str);
	new->type = type;
	new->next = NULL;
	return (new);
}