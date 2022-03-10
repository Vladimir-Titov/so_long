NAME = so_long
NAME_BONUS = so_long_bonus

CFLAGS = -Wall -Wextra -Werror

SRCS = $(GAME_SRCS) $(GNL_SRC)
SRCS_BONUS = $(BONUS_SRCS) $(GNL_SRC)

SRC = so_long.c	error.c	validate_map.c \
		utils.c	render_game.c	hook.c \
		validate_map2.c	move.c	move2.c \
		ft_put.c	ft_split.c \

BONUS_SRC = so_long.c	error.c	validate_map.c \
			utils.c	render_game.c	hook.c \
			validate_map2.c	move.c	move2.c \
			ft_put.c	ft_split.c	animation.c \
			ft_itoa.c	\

GAME_SRCS = $(addprefix src/, $(SRC))
BONUS_SRCS = $(addprefix bonus/, $(BONUS_SRC))

GNL = get_next_line.c get_next_line_utils.c
GNL_SRC = $(addprefix gnl/, $(GNL))

OBJ = $(SRCS:%.c=%.o)
OBJ_BONUS = $(SRCS_BONUS:%.c=%.o)

all	: $(NAME) $(NAME_BONUS)

bonus	: $(NAME_BONUS)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)

$(NAME_BONUS):	$(OBJ_BONUS) bonus/so_long.h
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(OBJ_BONUS) -o $(NAME_BONUS) 

%.o: %.c src/so_long.h
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:	
	rm -f $(OBJ) $(OBJ_BONUS)

fclean:	clean
	rm -f $(NAME) $(NAME_BONUS)

re	: 
	fclean all