/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:11:58 by jharras           #+#    #+#             */
/*   Updated: 2022/02/24 19:13:57 by jharras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	bind_image(t_game *game)
{
	game->img.border = mlx_xpm_file_to_image(game->vars_mlx.mlx,
			"img/brick2.xpm", &game->img.width, &game->img.height);
	game->img.space = mlx_xpm_file_to_image(game->vars_mlx.mlx,
			"img/grass.xpm", &game->img.width, &game->img.height);
	game->img.plr = mlx_xpm_file_to_image(game->vars_mlx.mlx,
			"img/man-stand.xpm", &game->img.width, &game->img.height);
	game->img.coin = mlx_xpm_file_to_image(game->vars_mlx.mlx,
			"img/coinGold.xpm", &game->img.width, &game->img.height);
	game->img.exit = mlx_xpm_file_to_image(game->vars_mlx.mlx,
			"img/exit.xpm", &game->img.width, &game->img.height);
	game->img.enemy = mlx_xpm_file_to_image(game->vars_mlx.mlx,
			"img/spikes.xpm", &game->img.width, &game->img.height);
}

static void	put_image(t_game *game)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	j = 0;
	map = game->map.map;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == BORDER)
				mlx_put_image_to_window(game->vars_mlx.mlx, game->vars_mlx.win,
					game->img.border, j * 64, i * 64);
			if (map[i][j] == COINS)
				mlx_put_image_to_window(game->vars_mlx.mlx, game->vars_mlx.win,
					game->img.coin, j * 64, i * 64);
			j++;
		}
		j = 0;
		i++;
	}
}

static void	put_image2(t_game *game)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	j = 0;
	map = game->map.map;
	while (map[i])
	{
		while (map[i][j])
		{
			// if (map[i][j] == PLAYER)
			// {
			// 	mlx_put_image_to_window(game->vars_mlx.mlx,
			// 		game->vars_mlx.win, game->img.plr, j * 64, i * 64);
			// 	j++;
			// }
			if (map[i][j] == EXIT)
				mlx_put_image_to_window(game->vars_mlx.mlx, game->vars_mlx.win,
					game->img.exit, j * 64, i * 64);
			j++;
		}
		j = 0;
		i++;
	}
}

static void	render_background(t_game *game)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	j = 0;
	map = game->map.map;
	while (map[i])
	{
		while (map[i][j])
		{
			mlx_put_image_to_window(game->vars_mlx.mlx, game->vars_mlx.win,
				game->img.space, j * 64, i * 64);
			j++;
		}
		j = 0;
		i++;
	}
}

void	render_map(t_game *game, int keycode)
{
	render_background(game);
	put_image(game);
	put_image2(game);
	print_player(game, keycode);
}
