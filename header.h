#ifndef HEADER_H
# define HEADER_H

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include "libft/libft.h"

void	conclusion_without_flags(char *dir_name);
void	conclusion(char *dir_name);
int		number_of_files(char *dir_name);
void	sort_by_ascii(char *dir_name);

#endif