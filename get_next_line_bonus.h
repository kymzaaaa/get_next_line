/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steve <steve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:34:09 by steve             #+#    #+#             */
/*   Updated: 2024/09/05 09:37:33 by steve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

# ifndef EOF
#  define EOF 0x1A
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# if BUFFER_SIZE > 99999999 || BUFFER_SIZE <= 0
#  error "BUFFER=SIZE must be greater than 0 and less than or equal to 99999999"
# endif

# define ERROR -42

typedef struct s_line
{
	char	*str;
	size_t	len;
	size_t	capacity;
}			t_line;

typedef struct s_fd_buffer
{
	char	buffer[BUFFER_SIZE];
	char	*cursor;
	int		buff_bytes;
}				t_fd_buffer;

char	*get_next_line(int fd);
char	ft_getchar(int fd);


#endif