/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_penetration.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:13:08 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/21 14:52:16 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file		*get_rootnames(t_file **head, const char *path, t_flags *flags)
{
	t_file			*new;
	DIR				*dir;
	struct dirent	*entry;

	dir = opendir(path);
	if (!dir)
	{
		perror("\ndiropen");
		return (NULL);
	}
	while ((entry = readdir(dir)) != NULL)
	{
		if (can_i_add_hidden_file(entry->d_name, flags) == 0)
			continue ;
		new = newlst(new, entry->d_name, path, flags);
		push_back(&(*head), new);
	}
	closedir(dir);
	return (*head);
}

char		*get_path(char *name, char *path)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = ft_strjoin(path, name);
	tmp2 = ft_strjoin(tmp1, "/");
	ft_strdel(&tmp1);
	return (tmp2);
}

void		rec_penetration(const char *path, t_flags *flags, int path_flag)
{
	t_file		*head;
	t_file		*tmp;
	char		*new_path;

	head = NULL;
	if (path_flag != 1)
		print_path(path);
	path_flag = 0;
	head = get_rootnames(&head, path, flags);
	sort_list(&head, flags);
	print_struct(&head, flags);
	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->type == T_DIR && ft_strcmp(tmp->name, "..") !=\
		0 && ft_strcmp(tmp->name, ".") != 0)
		{
			new_path = get_path(tmp->name, tmp->path);
			rec_penetration((const char *)new_path, flags, 0);
			ft_strdel(&new_path);
		}
		tmp = tmp->next;
	}
	if (head != NULL)
		structfree(&head);
}

void		rec_init(t_file *head, const char **argv, t_flags *flags)
{
	t_file	*tmp;
	char	*new_path;
	int		path_flag;

	path_flag = 0;
	head = struct_filenames(&head, (const char **)argv, "", flags);
	sort_list(&head, flags);
	print_without_dir(&head);
	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->type == T_DIR)
		{
			new_path = get_path(tmp->name, tmp->path);
			path_flag = is_onlyone_arg(head);
			rec_penetration((const char *)new_path, flags, path_flag);
			ft_strdel(&new_path);
		}
		tmp = tmp->next;
	}
	structfree(&head);
}
