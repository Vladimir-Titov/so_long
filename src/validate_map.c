/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 19:51:40 by jharras           #+#    #+#             */
/*   Updated: 2022/01/14 19:34:32 by jharras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_count_line(t_game *game)
{
	int		i;
	size_t	count;
	char	**map;

	map = game->map.map;
	i = 1;
	count = ft_strlen(map[0]);
	while (map[i] != '\0')
	{
		if (count != ft_strlen(map[i]))
			error_msg_and_exit("Map need be square!");
		i++;
	}
	game->map.col = count;
}

static void	check_border(t_game *game)
{
	int		i;
	char	**map;
	int		row;

	row = game->map.row - 1;
	map = game->map.map;
	i = 0;
	while (map[0][i] != '\0')
		if (map[0][i++] != BORDER)
			error_msg_and_exit("The map need sorrounded by wall!");
	i = 0;
	while (map[row][i])
		if (map[row][i++] != BORDER)
			error_msg_and_exit("The map need sorrounded by wall!");
	while (row >= 0)
		if (map[row--][i - 1] != BORDER)
			error_msg_and_exit("The map need sorrounded by wall!");
	i = 0;
	row = 0;
	while (row <= game->map.row - 1)
		if (map[row++][i] != BORDER)
			error_msg_and_exit("The map need sorrounded by wall!");
}

static void	check_items(t_game *game)
{
	char	**map;
	int		i;
	int		j;

	j = 0;
	i = 0;
	map = game->map.map;
	while (map[i])
	{
		if (map[i][j] == '\0')
		{
			j = 0;
			i++;
			continue ;
		}
		if (map[i][j] != PLAYER && map[i][j] != BORDER && map[i][j] != COINS
		&& map[i][j] != EXIT && map[i][j] != SPACE && map[i][j] != ENEMY )
			error_msg_and_exit("Not valid char on the map!");
		j++;
	}
}

void	validate_map(t_game *game)
{
	check_count_line(game);
	check_border(game);
	check_items(game);
	validate_count_items(game);
}

void	validate_type_map(char *map_path)
{
	int	index;

	index = 0;
	while (map_path[index] != '.')
		index++;
	if (ft_strcmp(map_path + index, ".ber") != 0)
		error_msg_and_exit("need map .ber format!");
}