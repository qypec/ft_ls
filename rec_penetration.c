/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_penetration.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:13:08 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/12 17:20:38 by yquaro           ###   ########.fr       */
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
		perror("diropen");
		exit(1);
	}
	while ((entry = readdir(dir)) != NULL)
	{
		if (can_i_add_hidden_file(entry->d_name, flags) == 0)
			continue ;
		new = newlst(new, entry->d_name, path); /* Никогда new != NULL, т.к. тут не может быть несуществующих файлов */
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

void		rec_penetration(const char *path, t_flags *flags) // рекурсия
{
	t_file		*head;
	t_file		*tmp;
	char		*new_path;

	head = NULL;
	print_path(path);
	head = get_rootnames(&head, path, flags); // заполняет матрицу именами, которые вытаскиваются из пути
	// matr = matrix_sort(head, &matr, flags);
	print_struct(&head);
	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->type == T_DIR && ft_strcmp(tmp->name, "..") != 0 && ft_strcmp(tmp->name, ".") != 0 && ft_strcmp(tmp->name, ".git") != 0) // если лист - папка 
		{
			new_path = get_path(tmp->name, tmp->path); 	// когда заходим в рекурсию, меняется директория. Чтобы работал stat, соединяем путь и имя папки, в которую заходим ( ./ + libft + / = ./libft/ )
			rec_penetration((const char *)new_path, flags);
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

	head = struct_filenames(&head, argv, "./", flags);
	// matr = matrix_sort(head, &matr, flags);
	print_without_dir(&head); /* функция печатает все файлы кроме директорий */
	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->type == T_DIR && ft_strcmp(tmp->name, "..") != 0 && ft_strcmp(tmp->name, ".") != 0 && ft_strcmp(tmp->name, ".git") != 0) // если лист - папка 
		{
			new_path = get_path(tmp->name, tmp->path); 	// когда заходим в рекурсию, меняется директория. Чтобы работал stat, соединяем путь и имя папки, в которую заходим ( ./ + libft + / = ./libft/ )
			rec_penetration((const char *)new_path, flags);
			ft_strdel(&new_path);
		}
		tmp = tmp->next;
	}
	structfree(&head);
}