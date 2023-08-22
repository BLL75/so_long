NAME = so_long
BONUS_NAME = so_long_bonus

SRC = src/main.c src/key_events.c src/fuctions_ber.c src/map_operations.c \
	  src/get_next_line.c src/moves.c src/actions.c src/validate_maps.c \
	  src/flood_fill.c src/size_map.c src/node_utils.c src/moves_utils.c \
	  src/graphics_operations.c src/main_utils.c src/map_loader.c src/graphics_utils.c

BONUS_SRC = bonus/main.c bonus/key_events.c \
            src/fuctions_ber.c src/map_operations.c \
            src/get_next_line.c src/moves.c src/actions.c src/validate_maps.c \
            src/flood_fill.c src/size_map.c src/node_utils.c src/moves_utils.c \
            src/graphics_operations.c src/main_utils.c src/map_loader.c src/graphics_utils.c

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	MLX = -L/usr/local/lib -lmlx -lXext -lX11 -lm -lbsd
endif
ifeq ($(UNAME_S),Darwin)
	MLX = -L/usr/local/lib -Imlx -lmlx -framework OpenGL -framework AppKit
endif

all: libft $(NAME)

bonus: libft $(BONUS_NAME)

libft:
	make -C libft

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX) -Llibft -lft

$(BONUS_NAME): $(BONUS_OBJ)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJ) $(MLX) -Llibft -lft

clean:
	rm -f $(OBJ) $(BONUS_OBJ)
	make clean -C libft

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	make fclean -C libft

re: fclean all

leaks:
	valgrind --leak-check=full ./$(NAME) ./maps/map_1.ber

.PHONY: all clean fclean re libft leaks bonus
