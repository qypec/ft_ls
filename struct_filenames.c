/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_filenames.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 19:26:40 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/17 17:42:32 by wconnell         ###   ########.fr       */
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

t_file		*newlst(t_file *new, const char *name, const char *path, t_flags *flags)
{
	int		type;
	char	*full_name;

	if (!(new = malloc(sizeof(t_file))))
		exit(1);
	full_name = ft_strjoin(path, name); // чтобы использовать stat в функции whatstype
	if (whatsspecific((const char *)full_name, &new, flags) == 0) /* вернет 0, если файла не существует */
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

t_file		*struct_filenames(t_file **head, const char **argv, const char *path, t_flags *flags) // без учета, что файл может начинаться на '-'
{
	t_file	*new;
	int		i;

	i = 1; /* чтобы не заносить ./ft_ls (argv[0]) в структуру */
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
