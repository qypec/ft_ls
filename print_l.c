/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 15:44:23 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/21 14:50:06 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		whatstools(t_file **new, mode_t mode, uid_t uid, gid_t gid)
{
	struct passwd	*pwd;
	struct group	*grp;

	if (S_ISREG(mode))
		(*new)->type = T_FILE;
	else if (S_ISDIR(mode))
		(*new)->type = T_DIR;
	else if (S_ISLNK(mode))
		(*new)->type = T_SYMBLINK;
	pwd = getpwuid(uid);
	(*new)->username = ft_strdup(pwd->pw_name);
	grp = getgrgid(gid);
	(*new)->groupname = ft_strdup(grp->gr_name);
}

void		print_l_tools(t_file *tmp, t_flags *flags)
{
	ft_putstr(tmp->chmod);
	ft_putstr("  ");
	ft_putstr(tmp->numlink);
	ft_putstr(" ");
	flags->g == 1 ? 0 : ft_putstr(tmp->username);
	flags->g == 1 ? 0 : ft_putstr("  ");
	ft_putstr(tmp->groupname);
	ft_putstr("  ");
	ft_putstr(tmp->size);
	ft_putstr(" ");
	ft_putstr(tmp->date);
	ft_putstr(" ");
	ft_putstr(tmp->name);
}

void		print_l(t_file **head, t_flags *flags)
{
	t_file	*tmp;
	char	buff[NAME_MAX + 1];
	char	*tmpstr;

	tmp = *head;
	*head = restruct(head);
	print_total(head);
	while (tmp != NULL)
	{
		print_l_tools(tmp, flags);
		if (tmp->type == T_SYMBLINK)
		{
			ft_bzero(buff, NAME_MAX + 1);
			tmpstr = ft_strjoin(tmp->path, tmp->name);
			readlink(tmpstr, buff, NAME_MAX);
			ft_strdel(&tmpstr);
			ft_putstr(" -> ");
			ft_putendl(buff);
		}
		else
			ft_putchar('\n');
		tmp = tmp->next;
	}
}
