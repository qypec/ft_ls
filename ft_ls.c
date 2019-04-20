/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:46:29 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/20 19:29:34 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		only_flags(const char **argv)
{
	int i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (is_it_flag(argv[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

int				main(int argc, char **argv)
{
	t_file		*head;
	t_flags		flags;

	flags = (t_flags){0, 0, 0, 0, 0};
	if (argc > 1)
	{
		find_flags((const char **)argv, argc, &flags);
		head = NULL;
		if (only_flags((const char **)argv) == 1) /* Если в argv только флаги, то заполняем матрицу названиями файлов из директории */
		{
			if (flags.bigr == 1)
				rec_penetration("./", &flags, 0);
			else
				print_dir("./", &flags);
		}
		else
		{
			if (flags.bigr == 1)
				rec_init(head, (const char **)argv, &flags);
			else
				init(head, argv, &flags);
		}
	}
	else
		print_dir("./", &flags);
}
