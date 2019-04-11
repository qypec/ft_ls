/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:46:29 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/11 20:24:36 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		no_argv(t_flags *flags)
{
	t_file		*head;
	char		**matr;

	head = NULL;
	matr = NULL;
	if (flags->R == 1) /* Если в есть флаг R, вызывает рекурсию */
		rec_penetration("./", flags);
	else
	{
		matr = get_rootnames(&matr, "./", flags);
		head = struct_filenames(&head, (const char **)matr, "./", flags);
		matr = matrix_sort(head, matr, flags);
		print(head, matr, flags);
	}
	ft_matrixfree(&matr);
	structfree(&head);
}

int		only_flags(const char **argv) // определяет только ли флаги в argv
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
	t_file		*tmp;
	t_flags		flags;
	char		**matr;

	flags = (t_flags){0, 0, 0, 0, 0};
	if (argc > 1)
	{
		find_flags((const char **)argv, argc, &flags); /* заполняет структуру флагами из argv */
		head = NULL;
		if (only_flags((const char **)argv) == 1) /* Если в argv только флаги, то заполняем матрицу названиями файлов из директории */
			no_argv(&flags);
		else /* если нет, то работаем только с теми файлами, что поданы в argv */
		{
			// yes_argv(&flags)
			if (flags.R == 1) /* Если в argv есть флаг R, вызывает рекурсию */
				rec_init(head, argv, &flags);
			else
				init(head, argv, &flags);
		}
	}
	printf("\nexit!");
	// else
	// 	conclusion_without_flags(".");
	
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

// нужно прикручивать возможность передачи файлов по пути ./ft_ls libft author authra libft/afaf - сейчас не выводит последнюю, так как find_list ее не находит.
// ./ft_ls -R tmp
