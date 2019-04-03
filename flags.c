/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wconnell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:33:38 by wconnell          #+#    #+#             */
/*   Updated: 2019/04/03 19:03:05 by wconnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	is_it_flag(char *s)
{
	if(s && s[0] == '-' && s[1])
		return(1);
	else
		return(0);
}
int find_flags(char **av, int ac, t_flags **flags)
{
	int i;

	i = 1;
	while (i <= ac)
	{
		if (is_it_flag(av[i]))
			putflag(av[i]);
		else

		i++;
	}

			
}
