/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:34:36 by jharras           #+#    #+#             */
/*   Updated: 2022/02/22 11:51:35 by jharras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		ft_putchar('-');
	}
	if (n <= 9)
	{
		ft_putchar(n + '0');
		return ;
	}
	ft_putnbr(n / 10);
	ft_putnbr(n % 10);
}

void	ft_putstr(char *s)
{
	size_t	len;

	if (s == NULL)
		return ;
	len = ft_strlen(s);
	write(1, s, len);
}
