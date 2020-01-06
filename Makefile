NAME = lem-in

FLAGS = -g -Wextra -Wall -Werror

INCLUDES_PATH = includes/

HEADER_FILES = includes/lem_in.h includes/libft.h includes/get_next_line.h

FILES = srcs/ft_farmnew.c srcs/ft_roomnew.c	srcs/get_next_line.c srcs/ft_farmfill.c srcs/ft_roomparse.c srcs/get_rooms.c srcs/ft_parsedata.c srcs/ft_getants.c srcs/main.c srcs/ft_dlisttoht.c srcs/get_edges.c srcs/ft_edgeparse.c srcs/queue.c srcs/ft_maxflow_extractor.c srcs/ft_maxflow_helper.c srcs/ft_maxflow_manager.c srcs/ft_maxflow.c srcs/ft_putinstructions.c srcs/ft_roomdel.c srcs/ft_farmdel.c srcs/ft_grpsdestroy.c srcs/sim_manager.c srcs/paths_manager.c srcs/ft_resprinter.c srcs/ft_roomdup.c

OBJ = $(FILES:.c=.o)

INCLUDES = includes/

all: $(NAME)

$(NAME) : $(OBJ) $(HEADER_FILES)
	make -C ./libft
	gcc $(FLAGS) $(OBJ) ./libft/libft.a -o $(NAME)

$(OBJ) : %.o : %.c
	gcc $(FLAGS)  $< -o $@ -c -I $(INCLUDES) -I $(INCLUDES)

clean :
	@rm -rf $(OBJ)
	@make clean -C ./libft

fclean : clean
	@rm -rf $(NAME)
	@make fclean -C ./libft

re : fclean all

#.PHONY : clean fclean re $(LIBFT)
