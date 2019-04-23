/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restruct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 13:59:58 by yquaro            #+#    #+#             */
/*   Updated: 2019/04/21 14:07:05 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file		*restruct_size(t_file **head)
{
	t_file	*tmp;
	int		maxlen;
	int		len;

	tmp = *head;
	maxlen = 0;
	while (tmp != NULL)
	{
		if ((len = ft_strlen(tmp->size)) > maxlen)
			maxlen = len;
		tmp = tmp->next;
	}
	tmp = *head;
	while (*head != NULL)
	{
		if ((len = ft_strlen((*head)->size)) < maxlen)
			(*head)->size = ft_addsymb((*head)->size, ' ', maxlen - len);
		(*head) = (*head)->next;
	}
	*head = tmp;
	return (*head);
}

t_file		*restruct_groupname(t_file **head)
{
	t_file	*tmp;
	int		maxlen;
	int		len;

	tmp = *head;
	maxlen = 0;
	while (tmp != NULL)
	{
		if ((len = ft_strlen(tmp->groupname)) > maxlen)
			maxlen = len;
		tmp = tmp->next;
	}
	tmp = *head;
	while (*head != NULL)
	{
		if ((len = ft_strlen((*head)->groupname)) < maxlen)
			(*head)->groupname = ft_addsymbend((*head)->groupname, \
			' ', maxlen - len);
		(*head) = (*head)->next;
	}
	*head = tmp;
	return (*head);
}

t_file		*restruct_username(t_file **head)
{
	t_file	*tmp;
	int		maxlen;
	int		len;

	tmp = *head;
	maxlen = 0;
	while (tmp != NULL)
	{
		if ((len = ft_strlen(tmp->username)) > maxlen)
			maxlen = len;
		tmp = tmp->next;
	}
	tmp = *head;
	while (*head != NULL)
	{
		if ((len = ft_strlen((*head)->username)) \
		< maxlen)
			(*head)->username = ft_addsymbend((*head)->username, \
			' ', maxlen - len);
		(*head) = (*head)->next;
	}
	*head = tmp;
	return (*head);
}

t_file		*restruct_numlink(t_file **head)
{
	t_file	*tmp;
	int		maxlen;
	int		len;

	tmp = *head;
	maxlen = 0;
	while (tmp != NULL)
	{
		if ((len = ft_strlen(tmp->numlink)) > maxlen)
			maxlen = len;
		tmp = tmp->next;
	}
	tmp = *head;
	while (*head != NULL)
	{
		if ((len = ft_strlen((*head)->numlink)) < maxlen)
			(*head)->numlink = ft_addsymb((*head)->numlink, ' ', maxlen - len);
		(*head) = (*head)->next;
	}
	*head = tmp;
	return (*head);
}

t_file		*restruct(t_file **head)
{
	*head = restruct_numlink(head);
	*head = restruct_username(head);
	*head = restruct_groupname(head);
	*head = restruct_size(head);
	return (*head);
}
