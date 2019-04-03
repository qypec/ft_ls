/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:46:29 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/03 19:41:34 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int main(int argc, char **argv)
{
	t_file	*name;
	t_file	*head;
	char	*flags;

	head = NULL;
	name = struct_filenames(&head, (const char **)argv);
	// if (argc == 1)
	// {
	// 	conclusion_without_flags(".");
	// 	exit(1);
	// }
	// else
	// {
	// 	if (argv[1][0] == '-')
	// 		flags = ft_strdup(argv[1]);
	// 	no_such_check(argv);
	// }
	// представим, что у нас пока только -R
	// argc = 2
	// argv[1] = "-R"
	// print();
}