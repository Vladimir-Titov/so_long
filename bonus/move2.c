/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:41:17 by jharras           #+#    #+#             */
/*   Updated: 2022/02/24 19:28:02 by jharras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_end_game(t_game *game, int y, int x)
{
	if (game->map.c_coin == 0)
	{
		game->end_game = 1;
		game->img.exit = mlx_xpm_file_to_image(game->vars_mlx.mlx,
				"img/exit_open.xpm", &game->img.width, &game->img.height);
		game->map.map[y][x] = '0';
		render_map(game, -1);
	}
}

int	check_move(t_game *game, int y, int x)
{
	if (game->map.map[y][x] != BORDER &&
		game->map.map[y][x] != EXIT &&
		game->map.map[y][x] != COINS)
		return (1);
	else if (game->map.map[y][x] == COINS)
	{
		game->map.c_coin--;
		check_end_game(game, y, x);
		return (1);
	}
	if (game->end_game == 1 && game->map.map[y][x] == EXIT)
	{
		write(1, "WIN!\n", 6);
		exit(0);
	}
	else
		return (0);
}
