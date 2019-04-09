/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatsspecific.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 20:31:12 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/09 19:29:34 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		whatsspecific(const char *str, t_file **new) // что насчет очистки buff? 
{
	struct stat buff;

	if (stat(str, &buff) < 0) // потом надо изменить на lstat
	{
		bust(str);
		return ;
	}
	(*new)->modif = buff.st_mtime;
	if (S_ISREG(buff.st_mode))
		(*new)->type = T_FILE;
    else if (S_ISDIR(buff.st_mode)) 
    	(*new)->type = T_DIR;
}