/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_filenames.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 19:26:40 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/11 23:49:57 by yquaro           ###   ########.fr       */
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

// void		filedelone(t_file **file)
// {
// 	if (file == NULL)
// 		return ;
// 	ft_strdel(&((*file)->name));
// 	ft_strdel(&((*file)->path));
// 	free(*file);
// 	*file = NULL;
// }

t_file		*newlst(t_file	*new, const char *name, const char *path)
{
	int		type;
	char	*full_name;

	full_name = ft_strjoin(path, name); // чтобы использовать stat в функции whatstype
	if (!(new = malloc(sizeof(t_file))))
		exit(1);
	if (whatsspecific((const char *)full_name, &new) == 0) /* вернет 0, если файла не существует */
	{
		bust((const char *)full_name);
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
		if (can_i_add_hidden_file(argv[i], flags) == 0)
		{
			i++;
			continue ;
		}
		if ((new = newlst(new, argv[i], (const char *)path)) == NULL)
		{
			i++;
			continue ;
		}
		push_back(&(*head), new);
		i++;
	}
	return (*head);
}