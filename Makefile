NAME = so_long

CFLAGS = -Wall -Wextra -Werror

SRCS = $(GAME_SRC) $(GNL_SRC)

SRC = so_long.c	error.c	validate_map.c \
		utils.c	render_game.c	hook.c \
		validate_map2.c	move.c	move2.c \
		ft_put.c	ft_split.c \
		
GAME_SRC = $(addprefix src/, $(SRC))

GNL = get_next_line.c get_next_line_utils.c
GNL_SRC = $(addprefix gnl/, $(GNL))

OBJ = $(SRCS:%.c=%.o)

all	: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)

%.o: %.c src/so_long.h
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:	
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean:	clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)