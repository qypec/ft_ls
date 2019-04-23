/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:20:11 by wconnell          #+#    #+#             */
/*   Updated: 2019/04/20 19:29:50 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_lstswap(t_file *p1, t_file *p2)
{
	t_file	tmp;

	tmp = *p1;
	content_cpy(p2, p1);
	content_cpy(&tmp, p2);
}

void	ascii_bubble(t_file **head, int n)
{
	t_file		*h;
	t_file		*p1;
	t_file		*p2;
	int			f;

	f = 1;
	while (f)
	{
		h = *head;
		f = 0;
		while (h->next != NULL)
		{
			p1 = h;
			p2 = h->next;
			if (n == 1 ? ft_strcmp(p1->name, p2->name) > 0 : \
			ft_strcmp(p1->name, p2->name) < 0)
			{
				ft_lstswap(p1, p2);
				f++;
			}
			h = h->next;
		}
	}
}

void	time_bubble(t_file **head, int n)
{
	t_file		*h;
	t_file		*p1;
	t_file		*p2;
	int			f;

	f = 1;
	while (f)
	{
		h = *head;
		f = 0;
		while (h->next != NULL)
		{
			p1 = h;
			p2 = h->next;
			if (n == 1 ? p1->modif < p2->modif : p1->modif > p2->modif)
			{
				ft_lstswap(p1, p2);
				f++;
			}
			h = h->next;
		}
	}
}

void	atime_bubble(t_file **head, int n)
{
	t_file		*h;
	t_file		*p1;
	t_file		*p2;
	int			f;

	f = 1;
	while (f)
	{
		h = *head;
		f = 0;
		while (h->next != NULL)
		{
			p1 = h;
			p2 = h->next;
			if (n == 1 ? p1->last_access < p2->last_access : \
			p1->last_access > p2->last_access)
			{
				ft_lstswap(p1, p2);
				f++;
			}
			h = h->next;
		}
	}
}

void	sort_list(t_file **head, t_flags *flags)
{
	if (*head != NULL)
	{
		flags->r == 1 ? ascii_bubble(head, 0) : ascii_bubble(head, 1);
		if (flags->t == 1)
		{
			if (flags->u == 1)
				flags->r == 1 ? atime_bubble(head, 0) : atime_bubble(head, 1);
			else
				flags->r == 1 ? time_bubble(head, 0) : time_bubble(head, 1);
		}
	}
}
