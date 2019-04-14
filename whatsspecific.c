/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatsspecific.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 20:31:12 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/13 21:42:29 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_chmod(mode_t mode)
{
	char *str;

	str = (char *)ft_memalloc(10);
	if (S_ISFIFO(mode))
		str[0] = 'p';
	else if (S_ISCHR(mode))
		str[0] = 'c';
	else if (S_ISBLK(mode))
		str[0] = 'b';
	else if (S_ISREG(mode))
		str[0] = '-';
	else if (S_ISSOCK(mode))
		str[0] = 's';
	else if (S_ISDIR(mode))
		str[0] = 'd';
	str[1] = ((mode & S_IRUSR)) ? 'r' : '-';
	str[2] = ((mode & S_IWUSR)) ? 'w' : '-';
	str[3] = ((mode & S_IXUSR)) ? 'x' : '-';
	str[4] = ((mode & S_IRGRP)) ? 'r' : '-';
	str[5] = ((mode & S_IWGRP)) ? 'w' : '-';
	str[6] = ((mode & S_IXGRP)) ? 'x' : '-';
	str[7] = ((mode & S_IROTH)) ? 'r' : '-';
	str[8] = ((mode & S_IWOTH)) ? 'w' : '-';
	if (mode & S_ISVTX && S_ISDIR(mode))
		str[9] = 't';
	else if (mode & S_ISVTX)
		str[9] = 'T';
	else if (mode & S_IXOTH)
		str[9] = 'x';
	else
		str[9] = '-';
	str[10] = '\0';
	return (str);
}

// char	*get_year(long int seconds)
// {
// 	char	*str;
// 	char	*year;
// 	int		i;
// 	int		j;
// 	int		len;

// 	str = ctime(&seconds);
// 		printf("time = %s\n", str);
// 	year = (char *)ft_memalloc(5);
// 	i = ft_strlen(str);
// 	while (str[i] != ' ')
// 		i++;
// 	printf("i = %d\n", i);
// 	return (year);
// }

char	*get_date(long int seconds)
{
	char	*str;
	char	*parse1;
	char	*parse2;

	str = ctime(&seconds);
	parse1 = ft_strncut(str, 4);
	parse2 = ft_strencut(parse1, 9);
	ft_strdel(&parse1);
	return (parse2);
}

int		whatsspecific(const char *str, t_file **new) // что насчет очистки buff? 
{
	struct stat		buff;
	struct passwd	*pwd;

	if (stat(str, &buff) < 0) // потом надо изменить на lstat
	{
		bust(str);
		return (0);
	}
	pwd = getpwuid(buff.st_uid);
	(*new)->chmod = get_chmod(buff.st_mode);
	(*new)->numlink = buff.st_nlink;
	(*new)->username = ft_strdup(pwd->pw_name);
	(*new)->size = buff.st_size;
	(*new)->modif = buff.st_mtime;
	(*new)->date = get_date((*new)->modif);
	(*new)->year = ft_strdup("2019");
	if (S_ISREG(buff.st_mode))
		(*new)->type = T_FILE;
    else if (S_ISDIR(buff.st_mode)) 
    	(*new)->type = T_DIR;
    return (1);
}