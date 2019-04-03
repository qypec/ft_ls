/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:20:38 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/03 18:55:36 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct		s_type
{
	char	*name;
	int		type;
}					t_type;

void	bust(char *file_name);

void	no_such_check(char **names);
char	*find_path(const char *name);

void	conclusion_without_flags(char *dir_name);
void	conclusion(char *dir_name);
int		number_of_files(char *dir_name);
char	**sort_by_ascii(char *dir_name);
void	print(void);


#endif