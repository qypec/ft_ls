/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:16:16 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/03 15:19:04 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print(void)
{
	DIR *dir;
    struct dirent *entry;
    struct stat buff;

    dir = opendir(".");
    while ((entry = readdir(dir)) != NULL) 
    {
    	stat(entry->d_name, &buff);
    	printf("%s\n", entry->d_name);
    	printf("%d\n\n", buff.st_mode);
    }
}