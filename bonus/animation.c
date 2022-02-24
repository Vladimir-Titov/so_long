/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:09:05 by jharras           #+#    #+#             */
/*   Updated: 2022/02/24 19:08:59 by jharras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	animation(t_game *game)
{
	char	*steps;

	steps = ft_itoa(game->player.count_steps);
	if (steps == NULL)
		error_msg_and_exit("Memory error!\n");
	mlx_string_put(game->vars_mlx.mlx, game->vars_mlx.win, 25, 25,
		0xFFFF00, "Steps: ");
	mlx_string_put(game->vars_mlx.mlx, game->vars_mlx.win, 100, 25,
		0xFFFF00, steps);
	free(steps);
	return (0);
}

