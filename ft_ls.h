/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:20:38 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/13 20:28:46 by yquaro           ###   ########.fr       */
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
#include <pwd.h>
#include <time.h>

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
	long int			modif;
	char				*date;
	char				*username;
	int					size;
	char				*year;
	int					numlink;
	char				*chmod;
	struct s_file		*next;
}						t_file;

int						find_flags(const char **av, int ac, t_flags *flags); /* создается и проверяется на валидность структура флагов */
int						is_it_flag(const char *s);

int						can_i_add_hidden_file(const char *str, t_flags *flags);

void					rec_init(t_file *head, const char **argv, t_flags *flags); /* подготовка к рекурсии */
void					rec_penetration(const char *path, t_flags *flags); /* основная рекурсия  */

void					init(t_file *head, char **argv, t_flags *flags);

t_file					*struct_filenames(t_file **head, const char **argv, const char *path, t_flags *flags); /* создает список из argv */
t_file					*get_rootnames(t_file **head, const char *path, t_flags *flags);
t_file					*newlst(t_file	*new, const char *name, const char *path); /* выделение памяти, заполнение информацией элемента списка */
char					*get_path(char *name, char *path);
int						whatsspecific(const char *str, t_file **new);
void					push_back(t_file **head, t_file *new);

void					print_struct(t_file **head, t_flags *flags);
void					print_dir(char *path, t_flags *flags);
void					print_without_dir(t_file **head, t_flags *flags);
void					print_path(const char *path);

void					bust(const char *file_name);
void					usage(char c);

void					structfree(t_file **head);

#endif
