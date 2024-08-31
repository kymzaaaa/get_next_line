/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steve <steve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 09:04:24 by steve             #+#    #+#             */
/*   Updated: 2024/08/31 09:20:10 by steve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

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

char	*get_next_line(int fd);

#endif