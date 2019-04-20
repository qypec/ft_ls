/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strencut.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 19:52:49 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/20 16:21:05 by wconnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strencut(char *str, int n)
{
	char	*segment;
	int		i;
	int		len;

	if (str == NULL)
		return (NULL);
	if (ft_strlen(str) < n || n < 0)
		return (NULL);
	if (ft_strlen(str) == n)
		return (NULL);
	i = 0;
	len = ft_strlen(str);
	segment = (char *)ft_memalloc(len - n);
	while (i != len - n)
	{
		segment[i] = str[i];
		i++;
	}
	segment[i] = '\0';
	return (segment);
}