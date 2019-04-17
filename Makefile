# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/17 20:00:49 by yquaro            #+#    #+#              #
#    Updated: 2019/04/17 20:01:06 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	gcc -o ft_ls struct_sort.c print.c rec_penetration.c init.c flags.c push_back.c struct_filenames.c whatsspecific.c bust.c ft_ls.c free_func.c libft/*.c
	# ./ft_ls filename
