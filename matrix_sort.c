/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wconnell <wconnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:49:17 by wconnell          #+#    #+#             */
/*   Updated: 2019/04/09 21:16:24 by wconnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void        sort_by_time(t_file *head, char **s)
{
     int    i;
     int    k;
     int    f;
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
            second = find_list(&head, s[i + 1]);
            if (first->modif < second->modif)
            {
                s = ft_strswap(s, i, i + 1);
                f++;
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
    if (!(new = (char**)malloc(sizeof(char *) * i)))
        return (NULL);
    new[i] = NULL;
    i--;
    while (i >= 0)
    {
        new[j] = s[i];
        j++;
        i--;
    }
    ft_matrixfree(&s);
    return(new);
}
char        **matrix_sort(t_file *head, char **s, t_flags *flags)
{
        if (flags->t == 1)
            sort_by_time(head, s);
        // if (flags->r == 1)
            // reverse_arr(s);
            return(s);
}