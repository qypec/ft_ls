/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wconnell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:20:11 by wconnell          #+#    #+#             */
/*   Updated: 2019/04/12 17:20:15 by wconnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	content_cpy(t_file *src, t_file *tmp)
{
	tmp->name = src->name;
	tmp->path = src->path;
	tmp->type = src->type;
	tmp->modif = src->modif;
	tmp->last_access = src->last_access;
	tmp->date = src->date;
	tmp->username = src->username;
	tmp->size = src->size;
	tmp->year = src->year;
	tmp->numlink = src->numlink;
	tmp->chmod = src->chmod;
	tmp->totalsize = src->totalsize;
}

void	ft_lstswap(t_file *p1, t_file *p2)
{
	t_file	tmp;

	tmp = *p1;
	content_cpy(p2, p1);
	content_cpy(&tmp, p2);
}

void	asciiBubble(t_file **head)
{
	t_file		*h;
	t_file		*p1;
	t_file		*p2;
	int 		f;

	f = 1;
	while (f)
	{
		h = *head;
		f = 0;
		while (h->next != NULL)
		{
			p1 = h;
			p2 = h->next;
			if (ft_strcmp(p1->name, p2->name) > 0)
			{
				ft_lstswap(p1, p2);
				f++;
			}
			h = h->next;
		}
	}
}
void	timeBubble(t_file **head)
{
	t_file		*h;
	t_file		*p1;
	t_file		*p2;
	int 		f;

	f = 1;
	while (f)
	{
		h = *head;
		f = 0;
		while (h->next != NULL)
		{
			p1 = h;
			p2 = h->next;
			if (p1->modif < p2->modif)
			{
				ft_lstswap(p1, p2);
				f++;
			}
			h = h->next;
		}
	}
}
void	revBubble(t_file **head)
{
	t_file		*h;
	t_file		*p1;
	t_file		*p2;
	int 		f;

	f = 1;
	while (f)
	{
		h = *head;
		f = 0;
		while (h->next != NULL)
		{
			p1 = h;
			p2 = h->next;
			if (ft_strcmp(p1->name, p2->name) < 0)
			{
				ft_lstswap(p1, p2);
				f++;
			}
			h = h->next;
		}
	}
}
void    atimeBubble(t_file **head)
{
    t_file		*h;
    t_file		*p1;
    t_file		*p2;
    int 		f;

    f = 1;
    while (f)
    {
        h = *head;
        f = 0;
        while (h->next != NULL)
        {
            p1 = h;
            p2 = h->next;
            if (p1->last_access < p2->last_access)
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
		asciiBubble(head);
		if (flags->t == 1)
		{
			if (flags->u == 1)
				atimeBubble(head);
			else
				timeBubble(head);
		}
		if (flags->r == 1)
			revBubble(head);
	}
}
