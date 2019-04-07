/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conclusion_without_flags.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 22:50:18 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/06 16:59:48 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	conclusion_without_flags(char *dir_name)
{
	char			**matrix;
	int				i;

	i = 0;
	matrix = sort_by_ascii(dir_name);
	while (matrix[i] != NULL)
	{
		if (matrix[i][0] != '.')
		{
			ft_putstr(matrix[i]);
			ft_putstr("\n");
		}
		i++;
	}
	matrix = ft_matrixfree(&matrix);
}