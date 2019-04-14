# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/03 15:12:58 by yquaro            #+#    #+#              #
#    Updated: 2019/04/13 13:48:55 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	gcc -o ft_ls struct_sort.c print.c rec_penetration.c init.c flags.c push_back.c struct_filenames.c whatsspecific.c bust.c ft_ls.c free_func.c libft/*.c
	# ./ft_ls filename
