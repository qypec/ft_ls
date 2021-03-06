/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:20:38 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/21 14:51:39 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <stdlib.h>
# include "libft.h"
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <limits.h>

# define T_FILE		1
# define T_DIR		2
# define T_SYMBLINK	3

typedef	struct			s_flags
{
	int					l;
	int					bigr;
	int					a;
	int					t;
	int					r;
	int					u;
	int					f;
	int					g;
}						t_flags;

typedef struct			s_file
{
	char				*name;
	char				*path;
	int					type;
	long long int		modif;
	long long int		last_access;
	char				*date;
	char				*username;
	char				*groupname;
	char				*chmod;
	char				*size;
	char				*numlink;
	long long int		blocks;
	struct s_file		*next;
}						t_file;

int						find_flags(const char **av, int ac, t_flags *flags);
int						is_it_flag(const char *s);
int						is_onlyone_arg(t_file *head);
int						can_i_add_hidden_file(const char *str, t_flags *flags);
void					rec_init(t_file *head, const char **argv, \
t_flags *flags);
void					rec_penetration(const char *path, t_flags *flags, \
int path_flag);
void					init(t_file *head, char **argv, t_flags *flags);
t_file					*struct_filenames(t_file **head, const char **argv, \
const char *path, t_flags *flags);
t_file					*get_rootnames(t_file **head, const char *path, \
t_flags *flags);
t_file					*newlst(t_file	*new, const char *name, \
const char *path, t_flags *flags);
char					*get_path(char *name, char *path);
int						whatsspecific(const char *str, t_file **new, \
t_flags *flags);
void					content_cpy(t_file *src, t_file *tmp);
void					push_back(t_file **head, t_file *new);
void					sort_list(t_file **head, t_flags *flags);
void					print_struct(t_file **head, t_flags *flags);
void					print_dir(char *path, t_flags *flags);
void					print_without_dir(t_file **head);
void					print_path(const char *path);
void					print_l(t_file **head, t_flags *flags);
void					print_total(t_file **head);
void					bust(const char *file_name);
void					usage(char c);
void					structfree(t_file **head);
t_file					*restruct(t_file **head);
void					whatstools(t_file **new, mode_t mode, \
uid_t uid, gid_t gid);

#endif
