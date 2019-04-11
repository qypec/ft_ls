/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 15:11:33 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/11 18:38:42 by yquaro           ###   ########.fr       */
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
	while (is_it_flag((const char *)argv[i]) == 1) // не учитывает того факта, что файл может начинаться на '-'
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
	// ft_putendl(name);
	t_file	*tmp;

	tmp = *head;
	// ft_putendl(tmp->name);
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