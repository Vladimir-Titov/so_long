NAME = so_long

CFLAGS = -Wall -Wextra -Werror

SRCS = $(GAME_SRC) $(GNL_SRC)

SRC = so_long.c	error.c	validate_map.c \
		utils.c
GAME_SRC = $(addprefix src/, $(SRC))

LIBFT_A = libft.a
LIBFT_DIR = libft/
LIBFT = $(addprefix $(LIBFT_DIR), $(LIBFT_A))

GNL = get_next_line.c get_next_line_utils.c
GNL_SRC = $(addprefix gnl/, $(GNL))

OBJ = $(SRCS:%.c=%.o)

all	: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:	
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean:	clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)