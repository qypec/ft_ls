/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 18:23:29 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/13 19:54:52 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncut(char *str, int n)
{
	char	*segment;
	int		i;
	int		j;

	if (str == NULL)
		return (NULL);
	if (ft_strlen(str) < n || n < 0)
		return (NULL);
	if (ft_strlen(str) == n)
		return (str);
	i = n;
	j = 0;
	segment = (char *)ft_memalloc(ft_strlen(str + n));
	while (str[i] != '\0')
	{
		segment[j] = str[i];
		i++;
		j++;
	}
	segment[j] = '\0';
	return (segment);
}
