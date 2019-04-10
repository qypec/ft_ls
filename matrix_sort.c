/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:49:17 by wconnell          #+#    #+#             */
/*   Updated: 2019/04/10 21:49:57 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		sort_by_time(t_file *head, char **s)
{
	int	i;
	int	k;
	int	f;
	t_file *first;
	t_file *second;
	f = 1;
	while (f)
	{   
		i = 0;
		f = 0;
		while (s[i] != NULL)
		{
			first = find_list(&head, s[i]);
			if(s[i + 1] != NULL)
			{
				second = find_list(&head, s[i + 1]);
				if (first->modif git < second->modif)
				{
					s = ft_strswap(s, i, i + 1);
					f++;
				}
			}
			i++;
		}
	}
}
char        **reverse_arr(char **s)
{
    int     i;
    int     j;
    char    **new;

    i = 0;
    j = 0;
    while (s[i] != NULL)
        i++;
	printf("%d\n", i);
    if (!(new = (char**)malloc(sizeof(char *) * i)))
        return (NULL);
    new[i] = NULL;
    i--;
	printf("%s", s[0]);
    while (i >= 0)
    {
        new[j] = ft_strdup(s[i]);
        j++;
        i--;
    }
	printf("%d\n", i);
	printf("%d\n", j);
    // ft_matrixfree(&s);
    return(new);
}
char        **matrix_sort(t_file *head, char **s, t_flags *flags)
{
	if (flags->t == 1)
		sort_by_time(head, s);
    if (flags->r == 1)
        s = reverse_arr(s);
    return(s);
}