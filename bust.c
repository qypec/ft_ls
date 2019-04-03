/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bust.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:50:11 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/03 21:33:03 by yquaro           ###   ########.fr       */
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