/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:38:51 by jharras           #+#    #+#             */
/*   Updated: 2022/02/24 19:27:19 by jharras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_window(t_game *game)
{
	game->width = game->map.col * 64;
	game->height = game->map.row * 64;
}

static void	init_game(t_game *game)
{
	game->map.col = 0;
	game->map.row = 0;
	game->map.c_coin = 0;
	game->map.c_exit = 0;
	game->map.c_plr = 0;
	game->player.count_steps = 0;
	game->end_game = 0;
	game->map.put_p = 0;
}

static void	check_empty_line(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if ((map[i] == '\n' && ft_strlen(map) == 1))
			error_msg_and_exit("Empty line!\n");
		i++;
	}
}

static void	read_map(char *map_path, t_game *game)
{
	int		fd;
	char	*buf;
	char	*line;
	char	**map;
	char	*tmp;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		error_msg_and_exit("Can't open map, try again");
	buf = ft_strdup("");
	while (21)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		check_empty_line(line);
		tmp = buf;
		buf = ft_strjoin(buf, line);
		free(line);
		free(tmp);
		game->map.row += 1;
	}
	map = ft_split(buf, '\n');
	game->map.map = map;
	free(buf);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_msg_and_exit("Use ./so_long *.ber\n");
	if (argc == 2)
	{
		init_game(&game);
		validate_type_map(argv[1]);
		read_map(argv[1], &game);
		validate_map(&game);
		init_window(&game);
	}
	game.vars_mlx.mlx = mlx_init();
	game.vars_mlx.win = mlx_new_window(game.vars_mlx.mlx, game.width,
			game.height, "so long");
	bind_image(&game);
	mlx_key_hook(game.vars_mlx.win, key_hook, &game);
	mlx_hook(game.vars_mlx.win, 17, 0, red_cross, &game);
	mlx_loop_hook(game.vars_mlx.mlx, animation, &game);
	mlx_loop(game.vars_mlx.mlx);
	exit(0);
}
