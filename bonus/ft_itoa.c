/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:33:07 by jharras           #+#    #+#             */
/*   Updated: 2022/02/24 18:42:06 by jharras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_negative(int number)
{
	if (number < 0)
		return (1);
	else
		return (0);
}

static int	count_digits(unsigned int number)
{
	int	count;

	count = 0;
	if (number == 0)
		return (1);
	while (number >= 1)
	{
		number /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	negative;
	unsigned int	number;
	unsigned int	digits;

	negative = is_negative(n);
	if (negative == 1)
		number = -n;
	else
		number = n;
	digits = count_digits(number);
	str = (char *)malloc(digits + negative + 1);
	if (str == NULL)
		return (NULL);
	if (negative == 1)
		str[0] = '-';
	str[digits + negative] = '\0';
	while (digits > 0)
	{
		str[(digits - 1) + negative] = (number % 10) + '0';
		number /= 10;
		digits--;
	}
	return (str);
}