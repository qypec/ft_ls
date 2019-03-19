/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:55:09 by yquaro            #+#    #+#             */
/*   Updated: 2018/12/08 14:29:33 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *str, size_t size)
{
	unsigned char	*new_str;
	size_t			length;
	size_t			i;

	i = 0;
	new_str = (unsigned char *)str;
	length = ft_strlen(str) + size + 1;
	new_str = (unsigned char *)malloc(sizeof(unsigned char) * length);
	while (new_str[i] != '\0')
		i++;
	while (i < length)
	{
		new_str[i] = '\0';
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
