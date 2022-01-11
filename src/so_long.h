/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 19:05:13 by jharras           #+#    #+#             */
/*   Updated: 2022/01/11 15:32:16 by jharras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}		t_vars;

typedef struct s_player
{
	int	x;
	int	y;
}		t_player;

typedef struct s_game
{
	char	**map;
	int		move;
	int		total_coins;
	int		coins;
	int		enemy;
	int		width;
	int		frame;
	char	*xpm_door;
	char	*xpm_thief;
}		t_game;

void	error_msg_and_exit(char *message);
void	validate_map(char *map_path);
int		ft_strcmp(const char *s1, const char *s2);

#endif