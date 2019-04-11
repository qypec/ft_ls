/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:49:17 by wconnell          #+#    #+#             */
/*   Updated: 2019/04/11 19:12:59 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		**sort_by_ascii(char **s)
{
	int		i;
	int		j;
	int		f;

	i = 0;
	j = 0;
	f = 1;
	while (f)
	{
		i = 0;
		f = 0;
		while(s[i] != NULL)
		{
			if (s[i + 1] != NULL)
			{
				if (ft_strcmp(s[i], s[i + 1]) > 0)
				{
					ft_strswap(s, i, i + 1);
					f++;
				}
			}
			i++;
		}
	}
	return(s);
}

void		sort_by_time(t_file *head, char **s)
{
	int		i;
	int		k;
	int		f;
	t_file	*first;
	t_file	*second;

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
				if (first->modif < second->modif)
				{
					s = ft_strswap(s, i, i + 1);
					f++;
				}
			}
			i++;
		}
	}
}

char	**reverse_arr(char **matr)
{
	int		i;
	int		num;
	char	**new;

	i = 0;
	num = 0;
	while (matr[i] != NULL)
	{
		num++;
		i++;
	}
	new = (char **)malloc(sizeof(char *) * num);
	i = 0;
	num--;
	while (matr[i] != NULL)
	{
		// printf("num = %d\n", num);
		new[num] = ft_strdup(matr[i]);
		num--;
		i++;
	}
	new[num] = NULL;
	ft_matrixfree(&matr);
	return (new);
}

// char        **reverse_arr(char **s)
// {
//     int     i;
//     int     j;
//     char    **new;

//     i = 0;
//     j = 0;
//     while (s[i] != NULL)
//         i++;
//     if (!(new = (char **)malloc(sizeof(char *) * i)))
//         return (NULL);
//     // new[i] = NULL;
//     i--;
//     while (i >= 0)
//     {
//         new[j] = ft_strdup(s[i]);
//         // new[j] = ft_strdup("145");
//         j++;
//         i--;
//     }
//     new[j] = NULL;
//     ft_matrixfree(&s);
//     return(new);
// }
char        **matrix_sort(t_file *head, char **s, t_flags *flags)
{
	// s = sort_by_ascii(s);
	if (flags->t == 1)
		sort_by_time(head, s);
    if (flags->r == 1)
        s = reverse_arr(s);
    return (s);
}