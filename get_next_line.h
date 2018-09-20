/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 11:54:00 by emaune            #+#    #+#             */
/*   Updated: 2018/07/02 14:38:15 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# define BUFF_SIZE 256

# include "libft/libft.h"
# include <fcntl.h>

typedef struct		s_gnl
{
	char			*reading_thread;
	char			*buffer;
	char			*line_thread;
	char			*t;
	int				bytes_read;
	int				fd;
	int				i;
	char			c;
	int				left_over_bytes;
}					t_gnl;

int					get_next_line(const int fd, char **line);

#endif
