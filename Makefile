NAME = so_long

SRCS = main.c

OBJ = $(SRCS:%.c=%.o)

all	: $(NAME)

$(NAME): $(OBJ)
	$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

clean:	
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)