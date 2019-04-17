/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:33:38 by wconnell          #+#    #+#             */
/*   Updated: 2019/04/17 17:19:33 by wconnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			is_it_flag(const char *s)
{
	if (s && s[0] == '-' && s[1])
		return (1);
	else
		return (0);
}

int			valid_flag(const char *s, char *v)
{
	int		i;
	int		j;
	int		f;

	i = 1;
	if (s[1] == '-' && !s[2])
		return (2);
	while (s[i] != '\0')
	{
		j = 0;
		f = 0;
		while (v[j] != '\0')
		{
			if (s[i] == v[j])
				f++;
			j++;
		}
		if (f == 0)
			usage(s[i]);
		i++;
	}
	return (1);
}

int			putflag(const char *av, t_flags *flags)
{
	int		i;
	int		f;

	i = 1;
	f = valid_flag(av, "lRatrufgd");
	if (f == 2)
		return (2);
	if (f)
	{
		while (av[i] != '\0')
		{
			av[i] == 'l' ? flags->l = 1 : 0;
			av[i] == 'R' ? flags->R = 1 : 0;
			av[i] == 'a' ? flags->a = 1 : 0;
			av[i] == 't' ? flags->t = 1 : 0;
			av[i] == 'r' ? flags->r = 1 : 0;
			av[i] == 'u' ? flags->u = 1 : 0;
			av[i] == 'f' ? flags->f = 1 : 0;
			av[i] == 'g' ? flags->g = 1 : 0;
			av[i] == 'd' ? flags->d = 1 : 0;
			i++;
		}
	}
	return (1);
}

void		disable_flags(t_flags *flags)
{
	flags->a = 1;
	flags->r = 0;
	flags->t = 0;
}

int			find_flags(const char **av, int ac, t_flags *flags)
{
	int		i;
	int		f;
	int		m;

	i = 1;
	f = 0;
	while (i <= ac)
	{
		if (is_it_flag(av[i]) && f == 0)
			m = putflag(av[i], flags);
		else
			f++;
		if (is_it_flag(av[i]) && f)
			bust(av[i]);
		m == 2 ? f++ : 0;
		i++;
	}
	if (flags->f == 1)
		disable_flags(flags);
	return (1);
}
