/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 15:16:15 by emaune            #+#    #+#             */
/*   Updated: 2018/06/29 13:18:43 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			wordlen(char const *s, char c)
{
	int				i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int			count_words(char *s, char c)
{
	int				words;

	words = 0;
	while (*s)
	{
		s = s + wordlen(s, c);
		while (*s == c && *s)
			s++;
		words++;
	}
	return (words);
}

static char			**malloc_split(char const *s, char c)
{
	char			**split_str;
	char			*trimmed_str;
	char			*temp;
	int				words;

	if (!s)
		return (NULL);
	trimmed_str = ft_strtrim(s);
	if (!trimmed_str)
		return (NULL);
	temp = trimmed_str;
	while (*trimmed_str == c && *trimmed_str)
		trimmed_str++;
	words = count_words(trimmed_str, c);
	ft_strdel(&temp);
	if (!(split_str = (char**)malloc(sizeof(char*) * words + 1)))
		return (NULL);
	split_str[words] = NULL;
	return (split_str);
}

static char			**malloc_strings(char const *s, char c)
{
	t_strsplit		v;

	v.i = 0;
	if (!s)
		return (NULL);
	v.split_str = malloc_split(s, c);
	if (!v.split_str)
		return (NULL);
	v.trimmed_str = ft_strtrim(s);
	if (!v.trimmed_str)
		return (NULL);
	v.temp = v.trimmed_str;
	while (*v.trimmed_str && *v.trimmed_str == c)
		v.trimmed_str++;
	while (*v.trimmed_str)
	{
		v.len = wordlen(v.trimmed_str, c);
		v.split_str[v.i] = ft_strnew(v.len);
		v.trimmed_str = v.trimmed_str + v.len;
		while (*v.trimmed_str && *v.trimmed_str == c)
			v.trimmed_str++;
		v.i++;
	}
	return (v.split_str);
}

char				**ft_strsplit(char const *s, char c)
{
	t_strsplit		v;

	v.i = 0;
	if (!s)
		return (NULL);
	v.split_str = malloc_strings(s, c);
	if (!v.split_str)
		return (NULL);
	v.trimmed_str = ft_strtrim(s);
	if (!v.trimmed_str)
		return (NULL);
	while (*v.trimmed_str)
	{
		v.j = 0;
		while (*v.trimmed_str == c && *v.trimmed_str)
			v.trimmed_str++;
		while (*v.trimmed_str != c && *v.trimmed_str)
		{
			v.split_str[v.i][v.j] = *v.trimmed_str;
			v.trimmed_str++;
			v.j++;
		}
		v.i++;
	}
	return (v.split_str);
}
