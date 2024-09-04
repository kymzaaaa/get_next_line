/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steve <steve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:29:50 by steve             #+#    #+#             */
/*   Updated: 2024/09/03 16:45:58 by steve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	ft_getc(int fd)
{
	static t_fd_buffer	fd_buffer[OPEN_MAX + 1];

	if (fd_buffer[fd].buff_bytes == 0)
	{
		fd_buffer[fd].buff_bytes = read(fd, fd_buffer[fd].buffer, BUFFER_SIZE);
		if (fd_buffer[fd].buff_bytes < 0)
			return (fd_buffer[fd].buff_bytes++, ERROR);
		fd_buffer[fd].cursor = fd_buffer[fd].buffer;
	}
	fd_buffer[fd].buff_bytes--;
	if (fd_buffer[fd].buff_bytes >= 0)
		return (*(fd_buffer[fd].cursor)++);
	return (fd_buffer[fd].buff_bytes++, EOF);
}

int	ft_putc(t_line *line, char c)
{
	char			*new_str;
	unsigned char	*dest;
	unsigned char	*src;
	size_t			len;

	if (line->len + 1 >= line->capacity)
	{
		line->capacity = (line->len + 1) * 2;
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
		if (c == ERROR)
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