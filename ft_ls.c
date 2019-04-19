/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:46:29 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/18 21:18:06 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		only_flags(const char **argv) /* определяет только ли флаги в argv */
{
	int i;

	i = 1;
	while (argv[i] != NULL) // не учитывает тот факт, что файл может называться на '-'
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
		find_flags((const char **)argv, argc, &flags); /* заполняет структуру флагами из argv */
		head = NULL;

		if (only_flags((const char **)argv) == 1) /* Если в argv только флаги, то заполняем матрицу названиями файлов из директории */
		{
			if (flags.R == 1)
				rec_penetration("./", &flags, 0);
			else
				print_dir("./", &flags);
		}
		else  /* если нет, то работаем только с теми файлами, что поданы в argv */
		{
			if (flags.R == 1)  /* Если в argv есть флаг R, вызывает рекурсию */
				rec_init(head, (const char **)argv, &flags);
			else
				init(head, argv, &flags);
		}
	}
	else
		print_dir("./", &flags);
}

	// while (head != NULL)
	// {
	// 	printf("name: %s\n", head->name);
	// 	printf("type: %d\n\n", head->type);
	// 	head = head->next;
	// }

	// printf("l = %d\n", flags.l);
	// printf("R = %d\n", flags.R);
	// printf("a = %d\n", flags.a);
	// printf("t = %d\n", flags.t);
	// printf("r = %d\n", flags.r);