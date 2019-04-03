/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_such_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:17:24 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/03 17:03:33 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			*find_path(const char *name)
{
	int cut_counter;
	int	i;

	i = 0;
	cut_counter = ft_strlen(name) - 1;
	if (name[i] == '/')
	{
		while (name[i] == '/')
			i++:
		if (name[i] ==)
	}


	while (cut_counter > 0)
	{
		if (name[cut_counter] == '/')
		{
			while (name[cut_counter] == '/')
				cut_counter--;
		}
		cut_counter--;
	}
	// printf("%d\n", cut_counter);
}

static void		check_other_dir(const char *name)
{
	DIR				*dir;
	struct dirent	*entry;
}

static void		check_this_dir(const char *name)
{
	DIR				*dir;
	struct dirent	*entry;
	int				counter;

	counter = 0;
	dir = opendir(".");
	if (!dir)
	{
		perror("diropen");
		exit(1);
	}
	while ((entry = readdir(dir)) != NULL)
	{
		if (ft_strcmp(entry->d_name, name) == 0)
			counter++;
	}
	if (counter == 0)
	{
		ft_putstr("ft_ls: ");
		ft_putstr(name);
		ft_putendl(": No such file or directory");
	}
	closedir(dir);
}

void	no_such_check(char **names)
{
	DIR				*dir;
	struct dirent	*entry;
	int				i;

	i = 0;
	while (names[i] != NULL)
	{
		if (ft_strchr(names[i], '/') == NULL)
			check_this_dir((const char *)names[i]);
		else
			check_other_dir((const char *)names[i]);
		i++;
	}
	// ft_putmatrix(names);

}