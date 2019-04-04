/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_filenames.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 19:26:40 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/04 18:08:27 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file		*struct_filenames(t_file **head, const char **argv) // без учета, что файл может начинаться на '-'
{
	t_file	*new;
	int		i;

	i = 0;
	while (argv[i] != NULL)
	{
		if (is_it_flag((char *)argv[i]) == 1)
		{
			i++;
			continue ;
		}
		if ((new = newlst(new, argv[i])) == NULL)
		{
			i++;
			continue ;
		}
		push_back(&(*head), new);
		i++;
	}
	return (*head);
}