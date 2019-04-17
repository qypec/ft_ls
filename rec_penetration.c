/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_penetration.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:13:08 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/17 17:16:21 by wconnell         ###   ########.fr       */
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
		// exit(1);
		return (NULL);
	}
	while ((entry = readdir(dir)) != NULL)
	{
		if (can_i_add_hidden_file(entry->d_name, flags) == 0)
			continue ;
		new = newlst(new, entry->d_name, path, flags); /* Никогда new != NULL, т.к. тут не может быть несуществующих файлов */
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

void		rec_penetration(const char *path, t_flags *flags, int path_flag) // рекурсия
{
	t_file		*head;
	t_file		*tmp;
	char		*new_path;

	head = NULL;
	if (path_flag != 1)
		print_path(path);
	path_flag = 0;
	head = get_rootnames(&head, path, flags); // заполняет матрицу именами, которые вытаскиваются из пути
	sort_list(&head, flags);
	print_struct(&head, flags);
	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->type == T_DIR && ft_strcmp(tmp->name, "..") != 0 && ft_strcmp(tmp->name, ".") != 0) // если лист - папка 
		{
			new_path = get_path(tmp->name, tmp->path); 	// когда заходим в рекурсию, меняется директория. Чтобы работал stat, соединяем путь и имя папки, в которую заходим ( ./ + libft + / = ./libft/ )
			rec_penetration((const char *)new_path, flags, 0);
			ft_strdel(&new_path);
		}
		tmp = tmp->next;
	}
	if (head != NULL)
		structfree(&head);
}

void		rec_init(t_file *head, const char **argv, t_flags *flags) // функция, из которой мы вызываем рекурсию
{
	t_file	*tmp;
	char	*new_path;
	int		path_flag;

	path_flag = 0;
	head = struct_filenames(&head, (const char **)argv, "", flags);
	sort_list(&head, flags);
	print_without_dir(&head, flags); /* функция печатает все файлы кроме директорий */
	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->type == T_DIR) // если лист - папка 
		{
			new_path = get_path(tmp->name, tmp->path); 	// когда заходим в рекурсию, меняется директория. Чтобы работал stat, соединяем путь и имя папки, в которую заходим ( ./ + libft + / = ./libft/ )
			path_flag = is_onlyone_arg(head);
			rec_penetration((const char *)new_path, flags, path_flag);
			ft_strdel(&new_path);
		}
		tmp = tmp->next;
	}
	structfree(&head);
}
