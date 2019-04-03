/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:46:29 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/03 21:24:15 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int main(int argc, char **argv)
{
	t_file	*head;
	char	*flags;

	head = NULL;
	head = struct_filenames(&head, (const char **)argv);

	while (head != NULL)
	{
		printf("name: %s\n", head->name);
		printf("type: %d\n\n", head->type);
		head = head->next;
	}
}