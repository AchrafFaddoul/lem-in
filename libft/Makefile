NAME = libft.a

SRCS =	ft_atoi.c			\
		ft_atol.c			\
		ft_islong.c			\
		ft_isulong.c		\
		ft_btreeadd.c		\
		ft_btreedel.c		\
		ft_btreefind.c		\
		ft_btreeinorder.c	\
		ft_btreenew.c		\
		ft_btreepostorder.c	\
		ft_btreepreorder.c	\
		ft_bzero.c			\
		ft_countof.c		\
		ft_indexof.c		\
		ft_isalnum.c		\
		ft_isalpha.c		\
		ft_isascii.c		\
		ft_isblank.c		\
		ft_isdigit.c		\
		ft_islower.c		\
		ft_isprint.c		\
		ft_isspace.c		\
		ft_isupper.c		\
		ft_itoa.c			\
		ft_itoa_base.c		\
		ft_lastindexof.c	\
		ft_lstadd.c			\
		ft_lstaddend.c		\
		ft_lstdel.c			\
		ft_lstdelone.c		\
		ft_lstfind.c		\
		ft_lstget.c			\
		ft_lstiter.c		\
		ft_lstmap.c			\
		ft_lstnew.c			\
		ft_lstremoveat.c	\
		ft_lstrev.c			\
		ft_lstsize.c		\
		ft_lstsort.c		\
		ft_memalloc.c		\
		ft_memccpy.c		\
		ft_memchr.c			\
		ft_memcmp.c			\
		ft_memcpy.c			\
		ft_memdel.c			\
		ft_memmove.c		\
		ft_memset.c			\
		ft_putchar.c		\
		ft_putchar_fd.c		\
		ft_putendl.c		\
		ft_putendl_fd.c		\
		ft_putlnbr.c		\
		ft_putlnbr_fd.c		\
		ft_putnbr.c			\
		ft_putnbr_fd.c		\
		ft_putstr.c			\
		ft_putstr_fd.c		\
		ft_putwchar.c		\
		ft_putwstr.c		\
		ft_strcat.c			\
		ft_strchr.c			\
		ft_strclr.c			\
		ft_strcmp.c			\
		ft_strcpy.c			\
		ft_strctrim.c		\
		ft_strdel.c			\
		ft_strdup.c			\
		ft_strendswith.c	\
		ft_strequ.c			\
		ft_striter.c		\
		ft_striteri.c		\
		ft_strjoin.c		\
		ft_strlcat.c		\
		ft_strlcpy.c		\
		ft_strlen.c			\
		ft_strmap.c			\
		ft_strmapi.c		\
		ft_strncat.c		\
		ft_strncmp.c		\
		ft_strncpy.c		\
		ft_strndup.c		\
		ft_strnequ.c		\
		ft_strnew.c			\
		ft_strnlen.c		\
		ft_strclen.c		\
		ft_strnstr.c		\
		ft_strpbrk.c		\
		ft_strrchr.c		\
		ft_strreplace.c		\
		ft_strrev.c			\
		ft_strsplit.c		\
		ft_strstartswith.c	\
		ft_strstr.c			\
		ft_strsub.c			\
		ft_strtolower.c		\
		ft_strtoupper.c		\
		ft_strtrim.c		\
		ft_tolower.c		\
		ft_toupper.c		\
		ft_wcsdup.c			\
		ft_wcslen.c			\
		ft_dlstdel.c		\
		ft_dlstnew.c		\
		ft_dlstpush.c		\
		ft_elemnew.c

OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))

INCLUDES = ../includes

INCLUDES_FILES = $(INCLUDES)/libft.h

FLAGS = -Wall -Wextra -Werror

OBJS_DIR = objs

all: $(NAME)

$(NAME): $(OBJS)
	@ar cr $(NAME) $(OBJS)

$(OBJS): $(OBJS_DIR)/%.o : %.c $(INCLUDES_FILES) | $(OBJS_DIR)
	@gcc -o $@ -c $< $(FLAGS) -I $(INCLUDES)

clean:
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

$(OBJS_DIR):
	@mkdir $(OBJS_DIR)
