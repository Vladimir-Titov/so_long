/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:38:36 by jharras           #+#    #+#             */
/*   Updated: 2022/02/22 11:51:45 by jharras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*one_case(char *res)
{
	res = (char *)malloc(sizeof(char) * 1);
	if (res == (NULL))
		return (NULL);
	res[0] = '\0';
	return (res);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;
	unsigned int	size;

	if (!s)
		return (NULL);
	size = ft_strlen((char *)s);
	if ((unsigned int)len > size)
		len = ft_strlen((char *)s);
	i = 0;
	if (len < start)
	{
		res = (NULL);
		return (one_case(res));
	}
	res = malloc(sizeof(char) * ((unsigned int)len + 1));
	if (res == (NULL))
		return (NULL);
	while (i < len)
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}

static size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			count++;
			while (*s != '\0' && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

static char	**alloc_mem(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = (char **)malloc(((count_words(s, c)) + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	return (result);
}

char	**ft_split(char const *s, char c)
{
	size_t		len;
	size_t		i;
	const char	*start;
	char		**result;

	result = alloc_mem(s, c);
	if (!result)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		while (*s && *s == c)
			s++;
		start = s;
		len = 0;
		while (*s && *s != c)
		{
			s++;
			len++;
		}
		if (*(s - 1) != c)
			result[i++] = ft_substr(start, 0, len);
	}
	result[i] = 0;
	return (result);
}
