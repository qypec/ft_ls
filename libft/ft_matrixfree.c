/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 15:13:08 by yquaro            #+#    #+#             */
/*   Updated: 2019/03/18 20:56:44 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_matrixfree(char ***ret, int len)
{
	char	**tmp;
	int		i;

	tmp = *ret;
	i = 0;
	while (i < len)
		free(tmp[i]);
	free(tmp);
	tmp = NULL;
	*ret = tmp;
	return (NULL);
}
