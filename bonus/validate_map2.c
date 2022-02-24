/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:34:46 by jharras           #+#    #+#             */
/*   Updated: 2022/02/22 14:31:09 by jharras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_count(t_game *game)
{
	if (game->map.c_plr < 1 || game->map.c_coin < 1 || game->map.c_exit < 1)
		error_msg_and_exit("Check count player, coins or exit!");
}

static void	check_ex_coins(char elem, t_game *game)
{
	if (elem == EXIT)
		game->map.c_exit += 1;
	if (elem == COINS)
		game->map.c_coin += 1;
}

static void	check_players(char *elem, t_game *game, int i, int j)
{
	if (*elem == PLAYER)
	{
		game->map.c_plr += 1;
		if (game->map.put_p == 0)
		{
			game->player.x = j;
			game->player.y = i;
		}
		game->map.put_p += 1;
		if (game->map.put_p > 1)
			*elem = SPACE;
	}
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
			check_players(&game->map.map[i][j], game, i, j);
			check_ex_coins(game->map.map[i][j], game);
			j++;
		}
		j = 0;
		i++;
	}
	check_count(game);
}
