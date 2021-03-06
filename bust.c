/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bust.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:50:11 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/21 14:48:22 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	bust(const char *file_name)
{
	ft_puterror("ft_ls: ");
	ft_puterror(file_name);
	ft_puterror(": No such file or directory");
	write(1, "\n", 1);
}

void	usage(char c)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("usage: ft_ls [-lRatrufg] [file ...]\n", 2);
	exit(1);
}
