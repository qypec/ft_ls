/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:20:38 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/09 20:53:59 by yquaro           ###   ########.fr       */
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

typedef	struct			s_flags
{
	int					l; // shows lots of shit 
	int					R; // recursive shit
	int					a; // show ".file" files
	int					t; // sort by timestamp
	int					r; // sort in reverse order
}						t_flags;

typedef struct			s_file
{
	char				*name;
	char				*path;
	int					type;
	long				modif;
	struct s_file		*next;
}						t_file;

int						find_flags(const char **av, int ac, t_flags *flags);
int						valid_flag(const char *s, char *v);
int						is_it_flag(const char *s);
int						putflag(const char *av, t_flags *flags);
void					usage(char c);

void					bust(const char *file_name);

void					filedelone(t_file **file);
t_file					*newlst(t_file	*new, const char *name, const char *path);
t_file					*struct_filenames(t_file **head, const char **matr, const char *path);
void					push_back(t_file **head, t_file *new);
int						whatsspecific(const char *str, t_file **new);

char					**get_rootnames(char ***ret, const char *path);
int						number_of_files(const char *dir_name);

void					init(t_file *head, char **matr, t_flags *flags);
t_file					*find_list(t_file **head, const char *name);

void					conclusion_without_flags(char *dir_name);
void					print(t_file *head, char **matr, t_flags *flags);
void					print_without_dir(t_file *head, const char **matr);

#endif
