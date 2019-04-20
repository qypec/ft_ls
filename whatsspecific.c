/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatsspecific.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 20:31:12 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/20 18:51:04 by wconnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_chmod(mode_t mode)
{
	char	*str;

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
	else if (S_ISLNK(mode))
		str[0] = 'l';
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

char	*get_date(long int seconds)
{
	long int	nowtime;
	char		*str;
	char		*parse1;
	char		*parse2;
	char		*tmp_year;
	char		*tmp;

	nowtime = time(NULL);
	str = ctime(&seconds);
	if (nowtime - seconds > 2592000 || nowtime - seconds < -3600)
	{
		parse1 = ft_strncut(str, 4, "second");
		tmp_year = ft_strencut(str, 5, "second");
		parse2 = ft_strencut(parse1, 14, "first");
		tmp = ft_strjoin(parse2, tmp_year);
		ft_strdel(&parse2);
		ft_strdel(&tmp_year);
		ft_strdel(&parse1);
		return (tmp);
	}
	else
	{
		parse1 = ft_strncut(str, 4, "second");
		parse2 = ft_strencut(parse1, 9, "first");
		ft_strdel(&parse1);
		return (parse2);
	}
}

int		whatsspecific(const char *str, t_file **new, t_flags *flags)
{
	struct stat		buff;
	struct passwd	*pwd;
	struct group	*grp;
	char			*no_leaksstr;

	if (lstat(str, &buff) < 0)
	{
		bust(str);
		return (0);
	}
	pwd = getpwuid(buff.st_uid);
	(*new)->chmod = get_chmod(buff.st_mode);
	no_leaksstr = ft_itoa(buff.st_nlink);
	(*new)->numlink = ft_strdup(no_leaksstr);
	ft_strdel(&no_leaksstr);
	(*new)->username = ft_strdup(pwd->pw_name);
	(*new)->filesize = buff.st_size;
	no_leaksstr = ft_itoa(buff.st_size);
	(*new)->size = ft_strdup(no_leaksstr);
	ft_strdel(&no_leaksstr);
	(*new)->modif = buff.st_mtime;
	(*new)->last_access = buff.st_atime;
	(*new)->date = flags->u == 1 ? get_date((*new)->last_access) :\
	get_date((*new)->modif);
	grp = getgrgid(buff.st_gid);
	(*new)->groupname = ft_strdup(grp->gr_name);
	if (S_ISREG(buff.st_mode))
		(*new)->type = T_FILE;
    else if (S_ISDIR(buff.st_mode))
    	(*new)->type = T_DIR;
    else if (S_ISLNK(buff.st_mode))
    	(*new)->type = T_SYMBLINK;
    return (1);
}
