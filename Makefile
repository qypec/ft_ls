# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/03 15:12:58 by yquaro            #+#    #+#              #
#    Updated: 2019/04/03 22:38:51 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	gcc -o ft_ls flags.c lst_func.c push_back.c struct_filenames.c whatsspecific.c bust.c ft_ls.c libft/*.c
	# ./ft_ls filename
