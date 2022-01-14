/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:34:46 by jharras           #+#    #+#             */
/*   Updated: 2022/01/14 20:03:50 by jharras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_count(t_game *game)
{
	if (game->map.c_plr != 1 || game->map.c_coin < 1 || game->map.c_exit != 1 )
		error_msg_and_exit("Check count player, coins or exit!");
}

void	validate_count_items(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map.map[i])
	{
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == PLAYER)
			{
				game->map.c_plr += 1;
				game->player.x = j;
				game->player.y = i;
			}
			if (game->map.map[i][j] == EXIT)
				game->map.c_exit += 1;
			if (game->map.map[i][j] == COINS)
				game->map.c_coin += 1;
			j++;
		}
		j = 0;
		i++;
	}
	check_count(game);
}
