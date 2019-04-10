/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_penetration.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:13:08 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/10 11:43:20 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		**argv_to_matrix(const char **argv, t_file *head, t_flags *flags)
{
	int		i;
	int		num;
	int		tmp;
	char	**matr;

	i = 0;
	num = 0;
	if (ft_strcmp(argv[0], "./ft_ls") == 0)
		i++;
	while (argv[i][0] == '-') // не учитывает того факта, что файл может начинаться на '-'
		i++;
	tmp = i;
	while (argv[i] != NULL)
	{
		num++;
		i++;
	}
	i = tmp;
	if (!(matr = (char**)malloc(sizeof(char *) * (num + 1))))
		return (NULL);
	tmp = 0;
	while (argv[i] != NULL)
	{
		// if (find_list(&head, argv[i]) != NULL)  если такой файл существует в struct 
		// {
			matr[tmp] = ft_strdup(argv[i]);
			tmp++;
		// }
		i++;
	}
	matr[tmp] = NULL;
	return (matr);
}

t_file		*find_list(t_file **head, const char *name)
{
	t_file	*tmp;

	tmp = *head;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->name, name) == 0)
			break ;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return (NULL);
	return (tmp);
}

int			number_of_files(const char *dir_name, t_flags *flags)
{
	DIR				*dir;
	struct dirent	*entry;
	int				count;

	count = 0;
	dir = opendir(dir_name);
	if (!dir)
	{
		perror("diropen");
		exit(1);
	}
	while ((entry = readdir(dir)) != NULL)
	{
		if (can_i_add_hidden_file(entry->d_name, flags) == 0)
			continue ;
		count++;
	}
	closedir(dir);
	return (count);
}

char		**get_rootnames(char ***ret, const char *path, t_flags *flags)
{
	DIR				*dir;
	struct dirent	*entry;
	char			**matr;
	int				i;
	int				num;

	i = 0;
	matr = *ret;
	// if (matr != NULL)
	// 	matr = ft_matrixfree(&matr);
	num = number_of_files(path, flags);
	// printf("path = %s\nnum = %d\n", path, num);
	dir = opendir(path);
	if (!dir) // можно убрать, т.к. в number_of_files это проверяется.
	{
		perror("diropen");
		exit(1);
	}
	if (!(matr = (char **)malloc(sizeof(char *) * (num + 1))))
		return (NULL);
	while ((entry = readdir(dir)) != NULL)
	{
		if (can_i_add_hidden_file(entry->d_name, flags) == 0)
			continue ;
		matr[i] = ft_strdup(entry->d_name);
		i++;
	}
	// printf("i = %d\n", i);
	matr[i] = NULL;
	closedir(dir);
	return (matr);
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
	// ft_putchar('\n');
	// ft_putstr(path);
	// ft_putchar(':');
	// ft_putchar('\n');
	i = 0;
	head = NULL;
	tmp = head;
	matr = get_rootnames(&matr, path, flags); // заполняет матрицу именами, которые вытаскиваются из пути
	// printf("matr[0] = %s\n", matr[0]);
	head = struct_filenames(&head, (const char **)matr, path, flags);
	// matr = matrix_sort(head, &matr, flags);
	print(head, matr, flags);

	while (matr[i] != NULL)
	{
		tmp = find_list(&head, matr[i]); // функция по имени из matrix находит нужный лист и возвращает указатель на него. Это сделано для того, чтобы не сортировать односвязный список
		// printf("tmp->name = %s\n", tmp->name);
		if (tmp->type == T_DIR && ft_strcmp(tmp->name, "..") != 0 && ft_strcmp(tmp->name, ".") != 0 && ft_strcmp(tmp->name, ".git") != 0) // если лист - папка 
		{	
			new_path = get_path(tmp->name, tmp->path); 	// когда заходим в рекурсию, меняется директория. Чтобы работал stat, соединяем путь и имя папки, в которую заходим ( ./ + libft + / = ./libft/ )
			// printf("new_path = %s\n", new_path);
			rec_penetration(new_path, flags);
			ft_strdel(&new_path);
		}
		// очистить tmp тут
		i++;
	}
}

void		rec_init(t_file *head, char **matr, t_flags *flags) // функция, из которой мы вызываем рекурсию
{
	printf("init");
	t_file	*tmp;
	char	*new_path;
	int		i;

	// ft_putmatrix(matr);
	i = 0;
	tmp = head;
	if (matr == NULL) /* matr будет равен NULL только если в init передали не argv */
	{
		matr = get_rootnames(&matr, "./", flags);
		head = struct_filenames(&head, (const char **)matr, "./", flags);
		// matr = matrix_sort(head, &matr, flags); // функция будет в зависимости от сортировочного флага сортировать матрицу
		print_without_dir(head, (const char **)matr);
	}
	else
	{
		matr = argv_to_matrix((const char **)matr, head, flags); /* заполняет матрицу из argv, включая несуществующие файлы */
		// ft_putmatrix(matr);

		head = struct_filenames(&head, (const char **)matr, "./", flags);
		// matr = matrix_sort(head, &matr, flags);
		print_without_dir(head, (const char **)matr); // функция должна печатать все файлы кроме директорий
	}

	while (matr[i] != NULL)
	{
		if ((tmp = find_list(&head, matr[i])) == NULL) // функция по имени из matrix находит нужный лист и возвращает указатель на него. Это сделано для того, чтобы не сортировать односвязный список
		{
			i++;		/* такое возможно если в аргументы подали несуществующий файл */
			continue ;
		}
		if (tmp->type == T_DIR && ft_strcmp(tmp->name, "..") != 0 && ft_strcmp(tmp->name, ".") != 0 && ft_strcmp(tmp->name, ".git") != 0) // если лист - папка 
		{
			new_path = get_path(tmp->name, tmp->path); 	// когда заходим в рекурсию, меняется директория. Чтобы работал stat, соединяем путь и имя папки, в которую заходим ( ./ + libft + / = ./libft/ )
			rec_penetration((const char *)new_path, flags);
			ft_strdel(&new_path);
		}
		// очистить tmp тут
		i++;
	}
}