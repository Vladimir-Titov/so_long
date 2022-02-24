/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 19:17:26 by jharras           #+#    #+#             */
/*   Updated: 2022/02/22 11:51:17 by jharras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_msg_and_exit(char *message)
{
	ft_putstr("Error\n");
	ft_putstr(message);
	exit(0);
}
