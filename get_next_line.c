/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 12:53:35 by emaune            #+#    #+#             */
/*   Updated: 2018/07/03 12:47:25 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			realloc_line_thread(t_gnl *v, char **line,
		char **reading_thread)
{
	if (ft_strchr(v->line_thread, '\n'))
	{
		if (*v->line_thread == '\n')
		{
			*line = ft_strdup("");
			*reading_thread = ft_strdup(v->line_thread + 1);
			ft_strdel(&v->line_thread);
			return (1);
		}
		*reading_thread = ft_strchr(v->line_thread, '\n') + 1;
		*(*reading_thread - 1) = '\0';
		*line = ft_strdup(v->line_thread);
		return (1);
	}
	v->t = v->line_thread;
	v->i++;
	v->line_thread = ft_strnew((BUFF_SIZE * v->i) + v->left_over_bytes);
	ft_strcat(v->line_thread, v->t);
	ft_strdel(&v->t);
	return (0);
}

static int			read_from_fd(t_gnl *v, char **line, char **reading_thread)
{
	while ((v->bytes_read = read(v->fd, v->buffer, BUFF_SIZE)) >= 0)
	{
		if (!v->bytes_read && *v->line_thread)
		{
			*line = ft_strdup(v->line_thread);
			return (1);
		}
		if (v->bytes_read <= 0)
			return (v->bytes_read);
		v->buffer[v->bytes_read] = '\0';
		ft_strcat(v->line_thread, v->buffer);
		if (realloc_line_thread(v, line, reading_thread))
			break ;
	}
	return (v->bytes_read <= 0 ? v->bytes_read : 1);
}

static int			read_from_reading_thread(t_gnl *v, char **line,
		char **reading_thread)
{
	if (ft_strchr(*reading_thread, '\n'))
	{
		v->t = *reading_thread;
		if (**reading_thread == '\n')
		{
			*line = ft_strdup("");
			**reading_thread = 0;
			*reading_thread = *reading_thread + 1;
			ft_strdel(&v->buffer);
			return (1);
		}
		*reading_thread = ft_strchr(*reading_thread, '\n') + 1;
		*(*reading_thread - 1) = '\0';
		*line = ft_strdup(v->t);
		return (1);
	}
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	static t_gnl	v;

	v.left_over_bytes = 0;
	v.i = 1;
	v.fd = fd;
	if (!line || BUFF_SIZE <= 0)
		return (-1);
	v.buffer = ft_strnew(BUFF_SIZE);
	v.line_thread = ft_strnew(BUFF_SIZE);
	if (!v.line_thread || !v.buffer)
		return (-1);
	if (v.reading_thread)
	{
		if (read_from_reading_thread(&v, line, &v.reading_thread))
			return (1);
		ft_strdel(&v.line_thread);
		v.left_over_bytes = ft_strlen(v.reading_thread);
		v.line_thread = ft_strnew(BUFF_SIZE + v.left_over_bytes);
		ft_strcat(v.line_thread, v.reading_thread);
		v.reading_thread = NULL;
	}
	return (read_from_fd(&v, line, &v.reading_thread));
}
