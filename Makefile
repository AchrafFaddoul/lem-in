# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/11 17:42:24 by afaddoul          #+#    #+#              #
#    Updated: 2019/10/01 15:36:21 by afaddoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
FLAGS = -g -Wextra -Wall -Werror
HEADER_FILES = includes/
FILES = srcs/ft_farmnew.c srcs/ft_roomnew.c	srcs/get_next_line.c srcs/ft_farmfill.c srcs/ft_roomparse.c srcs/get_rooms.c srcs/ft_parsedata.c srcs/get_ants.c srcs/main.c
OBJ = $(FILES:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ) $(HEADER_FILES)
	make -C ./libft
	gcc $(FLAGS) $(OBJ) ./libft/libft.a -o $(NAME)

$(OBJ) : %.o : %.c
	gcc $(FLAGS)  $< -o $@ -c -I $(HEADER_FILES) -I libft/
clean :
	@rm -rf $(OBJ)
	@make clean -C ./libft

fclean : clean
	@rm -rf $(NAME)
	@make fclean -C ./libft

re : fclean all
