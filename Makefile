NAME = so_long

SRC = \
read_map.c \
so_long.c \
utils_1.c \
utils_2.c \
check_map.c \
fill_structs.c \
load_textures_1.c \
load_textures_2.c \
map_rendering.c \
move_hook.c \
moves.c \
check_progress.c \
display_moves.c

OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft
PRINTF_DIR = printf
MLX42_DIR = MLX42

LIBFT_A = $(LIBFT_DIR)/libft.a
PRINTF_A = $(PRINTF_DIR)/libftprintf.a
MLX42_A = $(MLX42_DIR)/build/libmlx42.a

CFLAGS = -Wall -Wextra -Werror
MLX42_FLAGS = -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit

CC = gcc

all: $(NAME)

$(NAME): $(MLX42_A) $(LIBFT_A) $(PRINTF_A) $(OBJ)
	$(CC) $(CFLAGS) -I $(LIBFT_DIR) $(MLX42_FLAGS) $(LIBFT_A) $(PRINTF_A) $(MLX42_A) $(OBJ) -o $(NAME)

$(LIBFT_A):
	make -C libft

$(PRINTF_A):
	make -C printf

$(MLX42_A):
	git clone https://github.com/codam-coding-college/MLX42.git
	cd MLX42 && cmake -B build
	cd MLX42 && cmake --build build -j4

%.o: %.c
	$(CC) $(CFLAGS) -I $(LIBFT_DIR) -c -o $@ $^

clean:
	rm -f $(OBJ)
	make -C libft clean
	make -C printf clean

fclean: clean
	rm -f $(NAME) libft/libft.a printf/libftprintf.a

re: fclean all

.PHONY: all libft printf clean fclean re
