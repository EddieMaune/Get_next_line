/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 14:52:38 by emaune            #+#    #+#             */
/*   Updated: 2018/06/28 15:15:02 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			trim_beginning(t_strtrim *v, char const *s)
{
	while (s[v->i])
	{
		if (s[v->i] == ' ' || s[v->i] == '\t' || s[v->i] == '\n')
		{
			v->whitespace++;
			v->i++;
		}
		else
			break ;
	}
}

static void			trim_end(t_strtrim *v, char const *s)
{
	v->i = ft_strlen(s) - 1;
	v->start = v->whitespace;
	while (v->i > 0)
		if (s[v->i] == ' ' || s[v->i] == '\t' || s[v->i] == '\n')
		{
			v->whitespace++;
			v->i--;
		}
		else
			break ;
}

char				*ft_strtrim(char const *s)
{
	t_strtrim		v;

	v.whitespace = 0;
	v.i = 0;
	if (!s)
		return (NULL);
	trim_beginning(&v, s);
	if (v.whitespace == ft_strlen(s))
		return (ft_strnew(0));
	trim_end(&v, s);
	if (!(v.trimmed_str = ft_strnew(ft_strlen(s) - v.whitespace)))
		return (NULL);
	ft_strncpy(v.trimmed_str, s + v.start, ft_strlen(s) - v.whitespace);
	return (v.trimmed_str);
}
