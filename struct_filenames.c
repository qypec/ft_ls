/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_filenames.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 19:26:40 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/09 19:21:56 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		filedelone(t_file **file)
{
	if (file == NULL)
		return ;
	ft_strdel(&((*file)->name));
	ft_strdel(&((*file)->path));
	free(*file);
	*file = NULL;
}

t_file		*newlst(t_file	*new, const char *name, const char *path)
{
	int		type;
	char	*full_name;

	full_name = ft_strjoin(path, name); // чтобы использовать stat в функции whatstype
	if (!(new = malloc(sizeof(t_file))))
		exit(1);
	new->name = ft_strdup(name);
	new->path = ft_strdup(path);
	whatsspecific((const char *)full_name, &new);
	// if (type == 0) // если тип не определен это удаляет узел
	// {
	// 	filedelone(&new);
	// 	return (NULL);
	// }
	new->next = NULL;
	ft_strdel(&full_name);
	return (new);
}

t_file		*struct_filenames(t_file **head, const char **matr, const char *path) // без учета, что файл может начинаться на '-'
{
	t_file	*new;
	int		i;

	i = 0;
	if (ft_strcmp(matr[0], "./ft_ls") == 0) /* чтобы не заносить ./ft_ls в структуру */
		i++;
	while (matr[i] != NULL)
	{
		if (is_it_flag((const char *)matr[i]) == 1)
		{
			i++;
			continue ;
		}
		if ((new = newlst(new, matr[i], (const char *)path)) == NULL)
		{
			i++;
			continue ;
		}
		push_back(&(*head), new);
		i++;
	}
	// filedelone(&new);
	return (*head);
}