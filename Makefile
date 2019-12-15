NAME = lem-in

FLAGS = -g -Wextra -Wall -Werror

HEADER_FILES = includes/

FILES = srcs/ft_farmnew.c srcs/ft_roomnew.c	srcs/get_next_line.c srcs/ft_farmfill.c srcs/ft_roomparse.c srcs/get_rooms.c srcs/ft_parsedata.c srcs/ft_getants.c srcs/main.c srcs/ft_dlisttoht.c srcs/get_edges.c srcs/ft_edgeparse.c srcs/queue.c

OBJ = $(FILES:.c=.o)

INCLUDES = includes/

all: $(NAME)

$(NAME) : $(OBJ) $(HEADER_FILES)
	make -C ./libft
	gcc $(FLAGS) $(OBJ) ./libft/libft.a -o $(NAME)

$(OBJ) : %.o : %.c
	gcc $(FLAGS)  $< -o $@ -c -I $(HEADER_FILES) -I $(INCLUDES)
clean :
	@rm -rf $(OBJ)
	@make clean -C ./libft

fclean : clean
	@rm -rf $(NAME)
	@make fclean -C ./libft

re : fclean all
