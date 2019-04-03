/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_such_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:17:24 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/03 19:00:54 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// char			*find_path(const char *name)
// {
// 	int		cut_counter;
// 	int		i;

// 	i = 0;
// 	cut_counter = ft_strlen(name) - 1;
// 	if (name[0])
// }

// static void		check_other_dir(const char *name)
// {
// 	DIR				*dir;
// 	struct dirent	*entry;
// 	char			*dir_name;

// 	dir_name = find_path(name);
// 	dir = opendir(dir_name);
// 	if (!dir)
// 	{
// 		perror("diropen");
// 		exit(1);
// 	}
// 	while ((entry = readdir(dir)) != NULL)
// 	{
// }

// static void		check_this_dir(const char *name)
// {
// 	DIR				*dir;
// 	struct dirent	*entry;
// 	int				counter;

// 	counter = 0;
// 	dir = opendir(".");
// 	if (!dir)
// 	{
// 		perror("diropen");
// 		exit(1);
// 	}
// 	while ((entry = readdir(dir)) != NULL)
// 	{
// 		if (ft_strcmp(entry->d_name, name) == 0)
// 			counter++;
// 	}
// 	if (counter == 0)
// 	{
// 		ft_putstr("ft_ls: ");
// 		ft_putstr(name);
// 		ft_putendl(": No such file or directory");
// 	}
// 	closedir(dir);
// }

void	no_such_check(char **argv) // почистить dir_name
{
	DIR				*dir;
	struct dirent	*entry;
	int				i;
	char			*dir_name;

	i = 0;
	// while (argv[i] != NULL)
	// {
	// 	if (ft_strchr(argv[i], '/') == NULL)
	// 		check_dir((const char *)argv[i], ".");
	// 	else
	// 	{
	// 		dir_name = find_path(argv[i]);
	// 		check_dir((const char *)argv[i], dir_name);
	// 	}
	// 	i++;
	// }
	// ft_putmatrix(names);

}