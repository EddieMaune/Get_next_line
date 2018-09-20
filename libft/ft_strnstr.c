/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 12:35:11 by emaune            #+#    #+#             */
/*   Updated: 2018/06/28 12:36:17 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (!ft_strlen(needle))
		return ((char*)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		k = i;
		while (needle[j] && k < len)
			if (needle[j] == haystack[k])
			{
				j++;
				k++;
			}
			else
				break ;
		if (j == ft_strlen(needle))
			return ((char*)haystack + i);
		i++;
	}
	return (NULL);
}
