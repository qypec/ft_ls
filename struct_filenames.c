/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_filenames.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 19:26:40 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/20 18:44:37 by wconnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			can_i_add_hidden_file(const char *str, t_flags *flags)
{
	if (flags->a != 1)
	{
		if (str[0] == '.')
			return (0);
		else
			return (1);
	}
	return (1);
}

t_file		*newlst(t_file *new, const char *name, \
const char *path, t_flags *flags)
{
	char	*full_name;

	if (!(new = malloc(sizeof(t_file))))
		exit(1);
	full_name = ft_strjoin(path, name);
	if (whatsspecific((const char *)full_name, &new, flags) == 0)
	{
		ft_strdel(&full_name);
		return (NULL);
	}
	new->name = ft_strdup(name);
	new->path = ft_strdup(path);
	new->next = NULL;
	ft_strdel(&full_name);
	return (new);
}

t_file		*struct_filenames(t_file **head, const char **argv, \
const char *path, t_flags *flags)
{
	t_file	*new;
	int		i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (is_it_flag((const char *)argv[i]) == 1)
		{
			i++;
			continue ;
		}
		if ((new = newlst(new, argv[i], (const char *)path, flags)) == NULL)
		{
			i++;
			continue ;
		}
		push_back(&(*head), new);
		i++;
	}
	return (*head);
}
