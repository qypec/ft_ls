# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/03 15:12:58 by yquaro            #+#    #+#              #
#    Updated: 2019/04/03 21:12:19 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	gcc -o ft_ls lst_func.c push_back.c struct_filenames.c whatsspecific.c bust.c no_such_check.c ft_ls.c print.c number_of_files.c conclusion_without_flags.c sort_by_ascii.c libft/*.c
	# ./ft_ls filename
