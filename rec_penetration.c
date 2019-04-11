/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_penetration.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:13:08 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/11 20:24:19 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
	matr = get_rootnames(&matr, path, flags); // заполняет матрицу именами, которые вытаскиваются из пути

	// ft_putendl("rec");
	// ft_putendl(path);

	head = struct_filenames(&head, (const char **)matr, path, flags);
	matr = matrix_sort(head, matr, flags);
	print(head, matr, flags);

	// ft_putchar('\n');
	// ft_putstr("govno tyt\n");
	// while (head != NULL)
	// {
	// 	printf("rec_name: %s\n", head->name);
	// 	printf("rec_type: %d\n\n", head->type);
	// 	head = head->next;
	// }


	while (matr[i] != NULL)
	{
		// write(1, "a", 1);
		// ft_putstr(matr[i]);
		tmp = find_list(&head, matr[i]); // функция по имени из matrix находит нужный лист и возвращает указатель на него. Это сделано для того, чтобы не сортировать односвязный список
		// printf("tmp->name = %s\n", tmp->name);
		if (tmp->type == T_DIR && ft_strcmp(tmp->name, "..") != 0 && ft_strcmp(tmp->name, ".") != 0 && ft_strcmp(tmp->name, ".git") != 0) // если лист - папка 
		{	
			new_path = get_path(tmp->name, tmp->path); 	// когда заходим в рекурсию, меняется директория. Чтобы работал stat, соединяем путь и имя папки, в которую заходим ( ./ + libft + / = ./libft/ )
			// printf("new_path = %s\n", new_path);
			rec_penetration(new_path, flags);
			ft_strdel(&new_path);
		}
		i++;
	}
	ft_matrixfree(&matr);
	structfree(&head);
}

void		rec_init(t_file *head, char **argv, t_flags *flags) // функция, из которой мы вызываем рекурсию
{
	t_file	*tmp;
	char	*new_path;
	int		i;
	char	**matr;

	// ft_putmatrix(matr);
	i = 0;
	matr = argv_to_matrix((const char **)argv, head, flags); /* заполняет матрицу из argv, включая несуществующие файлы */
	head = struct_filenames(&head, (const char **)matr, "./", flags);
	matr = matrix_sort(head, matr, flags);
	print_without_dir(head, (const char **)matr); // функция должна печатать все файлы кроме директорий

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
		i++;
	}
	ft_matrixfree(&matr);
	structfree(&head);
}