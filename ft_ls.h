/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:20:38 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/03 21:44:45 by yquaro           ###   ########.fr       */
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

# define T_FILE	1
# define T_DIR	2

typedef struct		s_file
{
	char			*name;
	int				type;
	struct s_file	*next;
}					t_file;

void		bust(const char *file_name);

void		no_such_check(char **names);
char		*find_path(const char *name);

void		conclusion_without_flags(char *dir_name);
void		conclusion(char *dir_name);
int			number_of_files(char *dir_name);
char		**sort_by_ascii(char *dir_name);
void		print(void);

void		filedelone(t_file **file);
t_file		*newlst(t_file	*new, const char *str);

t_file		*struct_filenames(t_file **head, const char **argv);
void		push_back(t_file **head, t_file *new);

int			whatstype(const char *str);

#endif