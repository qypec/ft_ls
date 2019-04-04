/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:46:29 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/04 21:59:06 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int main(int argc, char **argv)
{
	t_file		*head;
	t_file		*tmp;
	t_flags		flags;

	flags = (t_flags){0, 0, 0, 0, 0};
	if (argc > 1)
	{
		find_flags(argv, argc, &flags);
		head = NULL;

		head = struct_filenames(&head, (const char **)argv, "./"); // Функция обрабатывает только argv.
																   // Нужно дописать в нее условие выхода,
																   // если в аргументах нет названий файлов
																   // В таком случае нужно заполнять матрицу
																   // не структурой, а из dirent.h с путем "."
		init(&head)

	}
	else
		conclusion_without_flags(".");
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