/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:45:29 by jharras           #+#    #+#             */
/*   Updated: 2022/02/22 11:11:48 by jharras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(char *str)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (-1);
		i++;
	}
	if (s1[i] != '\0' && s2[i] != '\0')
		return (-1);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	res = (char *)malloc(sizeof(char) * ((s1_len + s2_len) + 1));
	if (res == ((char *)0))
		return ((char *)0);
	while (i < s1_len)
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2_len)
		res[s1_len++] = s2[i++];
	res[s1_len] = '\0';
	return (res);
}
