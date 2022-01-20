/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 20:17:36 by jharras           #+#    #+#             */
/*   Updated: 2022/01/20 12:55:07 by jharras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_up(t_game *game)
{
	int	x;
	int	y;

	x = game->player.x;
	y = game->player.y;
	if (check_move(game, y - 1, x))
	{
		game->map.map[y][x] = '0';
		game->map.map[y - 1][x] = 'P';
		game->player.y -= 1;
		game->player.count_steps += 1;
	}
}

static void	move_down(t_game *game)
{
	int	x;
	int	y;

	x = game->player.x;
	y = game->player.y;
	if (check_move(game, y + 1, x))
	{
		game->map.map[y][x] = '0';
		game->map.map[y + 1][x] = 'P';
		game->player.y += 1;
		game->player.count_steps += 1;
	}
}

static void	move_left(t_game *game)
{
	int	x;
	int	y;

	x = game->player.x;
	y = game->player.y;
	if (check_move(game, y, x - 1))
	{
		game->map.map[y][x] = '0';
		game->map.map[y][x - 1] = 'P';
		game->player.x -= 1;
		game->player.count_steps += 1;
	}
}

static void	move_right(t_game *game)
{
	int	x;
	int	y;

	x = game->player.x;
	y = game->player.y;
	if (check_move(game, y, x + 1))
	{
		game->map.map[y][x] = '0';
		game->map.map[y][x + 1] = 'P';
		game->player.x += 1;
		game->player.count_steps += 1;
	}
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == W || keycode == UP)
		move_up(game);
	if (keycode == S || keycode == DOWN)
		move_down(game);
	if (keycode == A || keycode == LEFT)
		move_left(game);
	if (keycode == D || keycode == RIGHT)
		move_right(game);
	if (keycode == 53)
		exit(0);
	render_map(game);
	return (0);
}