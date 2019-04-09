/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatsspecific.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 20:31:12 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/08 21:21:15 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		whatstype(const char *str)
{
	struct stat buff;

	if (stat(str, &buff) < 0) // потом надо изменить на lstat
	{
		bust(str);
		return (0);
	}
		// perror("stat error");
	if (S_ISREG(buff.st_mode)) 
		return (T_FILE);
    else if (S_ISDIR(buff.st_mode)) 
    	return (T_DIR);
    return (0);
}