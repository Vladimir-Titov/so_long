/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 19:05:13 by jharras           #+#    #+#             */
/*   Updated: 2022/02/24 17:40:38 by jharras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../gnl/get_next_line.h"

# include <mlx.h>
# include <fcntl.h>

typedef enum e_items
{
	PLAYER = 'P',
	BORDER = '1',
	COINS = 'C',
	EXIT = 'E',
	SPACE = '0',
}	t_items;

typedef enum e_keycode
{
	W = 13,
	S = 1,
	A = 0,
	D = 2
}	t_keycode;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}		t_vars;

typedef struct s_player
{
	int	x;
	int	y;
	int	count_steps;
}		t_player;

typedef struct s_img
{
	void	*border;
	void	*plr;
	void	*coin;
	void	*exit;
	void	*space;
	int		width;
	int		height;
}		t_img;

typedef struct s_map
{
	char	**map;
	int		c_coin;
	int		c_plr;
	int		c_exit;
	int		col;
	int		row;
	int		put_p;
}		t_map;

typedef struct s_game
{
	t_vars		vars_mlx;
	t_map		map;
	t_img		img;
	t_player	player;
	int			height;
	int			width;
	int			end_game;
}		t_game;

void	error_msg_and_exit(char *message);
void	validate_type_map(char *map_path);
int		ft_strcmp(const char *s1, const char *s2);
void	validate_map(t_game *game);
void	render_map(t_game *game);
int		red_cross(t_game *game);
void	validate_count_items(t_game *game);
int		key_hook(int keycode, t_game *game);
int		check_move(t_game *game, int y, int x);
void	bind_image(t_game *game);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(char *str);
void	ft_putstr(char *s);
void	ft_putnbr(int n);
#endif