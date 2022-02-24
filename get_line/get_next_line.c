/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jharras <jharras@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:52:24 by jharras           #+#    #+#             */
/*   Updated: 2022/02/24 14:14:23 by jharras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	count_before_n_0(char *text)
{
	int	i;

	i = 0;
	while (text[i] && text[i] != '\n')
		i++;
	return (i);
}

static char	*make_line(char *text)
{
	int		i;
	char	*line;

	i = count_before_n_0(text);
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	ft_strlcpy(line, text, i + 2);
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

static char	*make_new_line(char *text)
{
	int		i;
	char	*new_text;

	i = count_before_n_0(text);
	if (text[i] == '\0')
	{
		free(text);
		return (NULL);
	}
	new_text = (char *)malloc(sizeof(char) * (gnl_strlen(text) - i + 1));
	if (!new_text)
		return (NULL);
	ft_strlcpy(new_text, text + i + 1, gnl_strlen(text) - i + 1);
	free(text);
	return (new_text);
}

static char	*copy_line(int fd, char *text, char	*buf)
{
	int		read_bt;
	int		find_n;
	char	*temp;

	read_bt = 1;
	find_n = 0;
	while (find_n == 0 && read_bt != 0)
	{
		read_bt = read(fd, buf, BUFFER_SIZE);
		if (read_bt < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[read_bt] = '\0';
		if (!text)
			text = ft_strdup("");
		temp = text;
		text = ft_gnl_strjoin(temp, buf);
		free(temp);
		if (ft_strchr(text, '\n'))
			find_n = 1;
	}
	free(buf);
	return (text);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*text;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
	{
		free(buf);
		return (NULL);
	}
	text = copy_line(fd, text, buf);
	if (!text)
		return (NULL);
	line = make_line(text);
	text = make_new_line(text);
	return (line);
}
