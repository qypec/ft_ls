# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/20 19:26:56 by yquaro            #+#    #+#              #
#    Updated: 2019/04/20 19:28:10 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	gcc -o ft_ls struct_sort.c print.c print_l.c print_total.c rec_penetration.c init.c flags.c push_back.c struct_filenames.c whatsspecific.c bust.c ft_ls.c free_func.c libft/*.c
	# ./ft_ls filename
