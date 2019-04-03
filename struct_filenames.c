/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_filenames.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 19:26:40 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/03 20:21:25 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		filename_start(const char **argv)
{
	int i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (argv[i][0] != '-')
			break ;
		i++;
	}
	return (i);
}

t_file		*struct_filenames(t_file **head, const char **argv) // без учета, что файл может начинаться на '-'
{
	t_file	*new;
	int		i;

	i = filename_start(argv);
	while (argv[i] != NULL)
	{
		new = newlst(new, argv[i]);
		push_back(&(*head), new);
		filedelone(&new);
		i++:
	}
}