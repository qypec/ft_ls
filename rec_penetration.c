/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_penetration.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:13:08 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/12 00:05:09 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// char		**argv_to_matrix(const char **argv, t_file *head, t_flags *flags)
// {
// 	int		i;
// 	int		num;
// 	int		tmp;
// 	char	**matr;

// 	i = 0;
// 	num = 0;
// 	if (ft_strcmp(argv[0], "./ft_ls") == 0)
// 		i++;
// 	while (argv[i][0] == '-') // не учитывает того факта, что файл может начинаться на '-'
// 		i++;
// 	tmp = i;
// 	while (argv[i] != NULL)
// 	{
// 		num++;
// 		i++;
// 	}
// 	i = tmp;
// 	if (!(matr = (char**)malloc(sizeof(char *) * (num + 1))))
// 		return (NULL);
// 	tmp = 0;
// 	while (argv[i] != NULL)
// 	{
// 		// if (find_list(&head, argv[i]) != NULL)  если такой файл существует в struct 
// 		// {
// 			matr[tmp] = ft_strdup(argv[i]);
// 			tmp++;
// 		// }
// 		i++;
// 	}
// 	matr[tmp] = NULL;
// 	return (matr);
// }

// t_file		*find_list(t_file **head, const char *name)
// {
// 	t_file	*tmp;

// 	tmp = *head;
// 	while (tmp != NULL)
// 	{
// 		if (ft_strcmp(tmp->name, name) == 0)
// 			break ;
// 		tmp = tmp->next;
// 	}
// 	if (tmp == NULL)
// 		return (NULL);
// 	return (tmp);
// }

// int			number_of_files(const char *dir_name, t_flags *flags)
// {
// 	DIR				*dir;
// 	struct dirent	*entry;
// 	int				count;

// 	count = 0;
// 	dir = opendir(dir_name);
// 	if (!dir)
// 	{
// 		perror("diropen");
// 		exit(1);
// 	}
// 	while ((entry = readdir(dir)) != NULL)
// 	{
// 		if (can_i_add_hidden_file(entry->d_name, flags) == 0)
// 			continue ;
// 		count++;
// 	}
// 	closedir(dir);
// 	return (count);
// }

t_file		*get_rootnames(t_file **head, const char *path, t_flags *flags)
{
	t_file			*new;
	DIR				*dir;
	struct dirent	*entry;

	// if (*head == NULL)
		// printf("head = null \n");
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
	char		**matr;
	int			i;
	char		*new_path;

	print_path(path);

	i = 0;
	head = NULL;
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
	// structfree(&head);
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
	// structfree(&head);
}