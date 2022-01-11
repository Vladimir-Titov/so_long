/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 19:51:40 by jharras           #+#    #+#             */
/*   Updated: 2022/01/11 15:26:34 by jharras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_map(char *map_path)
{
	int	index;

	index = 0;
	while (map_path[index] != '.')
		index++;
	if (ft_strcmp(map_path + index, ".ber") != 0)
		error_msg_and_exit("need map .ber format!");
	if (fd < 0)
		error_msg_and_exit("Can't open map,try again");
}