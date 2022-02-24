/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 19:09:39 by jharras           #+#    #+#             */
/*   Updated: 2022/02/24 19:29:42 by jharras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	bind_img_player(t_game *game)
{
	game->img.plr = mlx_xpm_file_to_image(game->vars_mlx.mlx,
			"img/man_stand.xpm", &game->img.width, &game->img.height);
	game->img.plr_run1 = mlx_xpm_file_to_image(game->vars_mlx.mlx,
			"img/man-run1.xpm", &game->img.width, &game->img.height);
	game->img.plr_run2 = mlx_xpm_file_to_image(game->vars_mlx.mlx,
			"img/man_run2.xpm", &game->img.width, &game->img.height);
	game->img.plr_run3 = mlx_xpm_file_to_image(game->vars_mlx.mlx,
			"img/man-run3.xpm", &game->img.width, &game->img.height);
}

void	print_player(t_game *game, int keycode)
{
	if (keycode == A)
	{
		mlx_put_image_to_window(game->vars_mlx.mlx, game->vars_mlx.win,
					game->img.plr_run1, game->player.y * 64, game->player.x * 64);
	}
	if (keycode == D)
	{
		mlx_put_image_to_window(game->vars_mlx.mlx, game->vars_mlx.win,
					game->img.plr_run2, game->player.y * 64, game->player.x * 64);
	}
}
