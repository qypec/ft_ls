/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:46:29 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/06 18:44:19 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		only_flags(char **argv) // определяет только ли флаги в argv
{
	int i;

	i = 1;
	while (argv[i] != NULL) // не учитывает тот факт, что файл может называться на '-'
	{
		if (argv[i][0] == '-')
			i++;
		else
			return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_file		*head;
	t_file		*tmp;
	t_flags		flags;
	char		**matr;

	flags = (t_flags){0, 0, 0, 0, 0};
	// printf("matr[i] = %s\nlist = %s\n\n", argv[1], tmp->name);
	if (argc > 1)
	{
		find_flags(argv, argc, &flags); // заполняет структуру флагов флагами
		head = NULL;
		if (only_flags(argv) == 0)
		{
			matr = NULL;
			init(head, matr, &flags);
		}
		else
		{
			head = struct_filenames(&head, (const char **)argv, "./");
			init(head, argv, &flags);
		}
	}
	// else
	// 	conclusion_without_flags(".");
	// free(flags); // ??
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