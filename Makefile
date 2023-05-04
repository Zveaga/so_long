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
MLX42_DIR = MLX42

LIBFT_A = $(LIBFT_DIR)/libft.a
MLX42_A = $(MLX42_DIR)/build/libmlx42.a

CFLAGS = -Wall -Wextra -Werror
MLX42_FLAGS = -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit

CC = cc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -I $(LIBFT_DIR) $(LIBFT_A) -I $(MLX42_DIR) $(MLX42_A) $(MLX42_FLAGS) $(OBJ) -o $(NAME)

$(LIBFT_A):
	make -C libft

$(MLX42_A): MLX42/CMakeLists.txt
	cd MLX42 && cmake -B build
	cd MLX42 && cmake --build build -j4

%.o: %.c | $(LIBFT_A)
	$(CC) $(CFLAGS) -I $(LIBFT_DIR) -c -o $@ $^

clean:
	rm -f $(OBJ)
	make -C libft clean
#make -C MLX42/build clean

fclean: clean
	rm -f $(NAME) libft/libft.a

re: fclean all

.PHONY: all libft clean fclean re