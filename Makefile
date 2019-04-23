# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/20 19:26:56 by yquaro            #+#    #+#              #
#    Updated: 2019/04/21 16:09:20 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS =  -Wall -Wextra -Werror
NAME = ft_ls
SRC = restruct.c struct_sort.c print.c print_l.c print_total.c rec_penetration.c init.c flags.c push_back.c struct_filenames.c whatsspecific.c bust.c ft_ls.c free_func.c
OBJS = restruct.o struct_sort.o print.o print_l.o print_total.o rec_penetration.o init.o flags.o push_back.o struct_filenames.o whatsspecific.o bust.o ft_ls.o free_func.o

all: $(NAME)
$(NAME):
	make -C libft/ re
	gcc $(CFLAGS) -g -o $(NAME) $(SRC) -I libft/includes/ -L libft/ -lft
clean:
	make -C libft/ clean
	/bin/rm -f $(OBJS)
fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)
re: fclean all
