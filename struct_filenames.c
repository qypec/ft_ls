/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_filenames.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 19:26:40 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/04 20:38:00 by yquaro           ###   ########.fr       */
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

char		*get_path(char *name, char *path)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = ft_strjoin(path, name);
	tmp2 = ft_strjoin(name, "/");
	ft_strdel(&tmp1);


}

t_file		*newlst(t_file	*new, const char *name, char *path)
{
	int type;

	if (!(new = malloc(sizeof(t_file))))
		exit(1);
	new->name = ft_strdup(name);
	new->path = get_path(name, path);
	type = whatstype(name);
	// if (type == 0) // если тип не определен это удаляет узел
	// {
	// 	filedelone(&new);
	// 	return (NULL);
	// }
	new->type = type;
	new->next = NULL;
	return (new);
}

t_file		*struct_filenames(t_file **head, const char **matr, char *path) // без учета, что файл может начинаться на '-'
{
	t_file	*new;
	int		i;

	i = 0;
	while (matr[i] != NULL)
	{
		if (is_it_flag((char *)matr[i]) == 1)
		{
			i++;
			continue ;
		}
		if ((new = newlst(new, matr[i], path)) == NULL)
		{
			i++;
			continue ;
		}
		push_back(&(*head), new);
		i++;
	}
	return (*head);
}