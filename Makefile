NAME = so_long

SRC = \
read_map.c \
so_long.c \
utils.c \
check_map.c \
fill_structs.c \
utils_map.c \

OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft

LIBFT_A = $(LIBFT_DIR)/libft.a

CFLAGS = -Wall -Wextra -Werror

CC = cc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -I $(LIBFT_DIR) $(LIBFT_A) $(OBJ) -o $(NAME)

$(LIBFT_A):
	make -C libft

%.o: %.c | $(LIBFT_A)
	$(CC) $(CFLAGS) -I $(LIBFT_DIR) -c -o $@ $^

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME) libft/libft.a

re: fclean all

.PHONY: all libft clean fclean re