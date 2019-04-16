/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 09:28:02 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/12 21:01:14 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

<<<<<<< HEAD
=======
// int			are_dots_in_argv(char **argv)
// {
// 	int	i;
// 	int	counter;
	
// 	i = 0;
// 	counter = 0;
// 	while (argv[i] != NULL)
// 	{
// 		if (ft_strcmp(tmp->name, "..") != 0 && ft_strcmp(tmp->name, ".") != 0)

// 	}
// }

>>>>>>> 235d3c0dddcd4b2d2cc532fd5163c2bf3a4ae3fe
int			is_onlyone_arg(t_file *head)
{
	t_file	*tmp;
	int		counter;

	counter = 0;
	tmp = head;
	while (tmp != NULL)
	{
		counter++;
		tmp = tmp->next;
	}
	if (counter == 1)
		return (1);
	return (0);
}

void		init(t_file *head, char **argv, t_flags *flags)
{
	t_file	*tmp;
	char	*new_path;
	int 	i;

	i = 0;
	head = struct_filenames(&head, (const char **)argv, "./", flags);
	sort_list(&head, flags);
	print_without_dir(&head, flags); /* функция печатает все файлы кроме директорий */
	tmp = head;
	while (tmp != NULL)
	{
<<<<<<< HEAD
		if (tmp->type == T_DIR && ft_strcmp(tmp->name, "..") != 0 && ft_strcmp(tmp->name, ".") != 0)
=======
		if (tmp->type == T_DIR)
>>>>>>> 235d3c0dddcd4b2d2cc532fd5163c2bf3a4ae3fe
		{
			if (is_onlyone_arg(head) != 1)
				print_path(tmp->name);
			new_path = get_path(tmp->name, tmp->path);
			print_dir(new_path, flags);
			ft_strdel(&new_path);
		}
		tmp = tmp->next;
	}
	structfree(&head);
}
