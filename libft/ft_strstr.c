/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 12:17:40 by emaune            #+#    #+#             */
/*   Updated: 2018/06/28 12:29:51 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	char	*p;

	i = 0;
	j = 0;
	if (!ft_strlen(needle))
		return ((char*)haystack);
	while (haystack[i])
	{
		p = ft_strchr(haystack + i, *needle);
		if (p)
			while (needle[j])
			{
				if (p[j] == needle[j])
					j++;
				else
					break ;
				if (j == ft_strlen(needle))
					return (p);
			}
		j = 0;
		i++;
	}
	return (NULL);
}
