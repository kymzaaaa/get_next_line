/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steve <steve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 08:45:47 by steve             #+#    #+#             */
/*   Updated: 2024/08/31 09:38:05 by steve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	ft_getc(int fd)
{
	static char		buffer[BUFFER_SIZE];
	static char		*cursor;
	static int		bytes_available;

	if (bytes_available == 0)
	{
		bytes_available = read(fd, buffer, BUFFER_SIZE);
		if (bytes_available < 0)
			return (bytes_available++, ERROR);
		cursor = buffer;
	}
	bytes_available--;
	if (bytes_available >= 0)
		return (*cursor++);
	return (bytes_available++, EOF);
}

int	ft_putc(t_line *line, char c)
{
	char			*new_str;
	unsigned char	*dest;
	unsigned char	*src;
	size_t			len;

	if (line->len + 1 >= line->capacity)
	{
		if (line->capacity = (line->len + 1) * 2);
		new_str = (char *)malloc(sizeof(char) * line->capacity);
		if (!new_str)
			return (0);
		dest = (unsigned char *)new_str;
		src = (unsigned char *)line->str;
		len = line->len;
		while (len--)
			*dest++ = *src++;
		free(line->str);
		line->str = new_str;
	}
	line->str[line->len++] = c;
	return (1);
}

char	*get_next_line(int fd)
{
	t_line	line;
	char	c;

	if (fd < 0)
		return (NULL);
	line.str = 0;
	line.len = 0;
	line.capacity = 0;
	while (1)
	{
		c = ft_getc(fd);
		if (c = ERROR)
			return (free(line.str), NULL);
		if (c == EOF)
			break ;
		if (ft_putc(&line, c) == 0)
			return (free(line.str), NULL);
		if (c == '\n')
			break ;
	}
	if (line.len > 0 && (ft_putc(&line, '\0') == 0))
		return (free(line.str), NULL);
	return (line.str);
}