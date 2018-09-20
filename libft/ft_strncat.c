/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 13:08:17 by emaune            #+#    #+#             */
/*   Updated: 2018/06/28 13:08:21 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = s1 + ft_strlen(s1);
	while (i < n && s2[i])
	{
		str[i] = s2[i];
		i++;
	}
	str[i] = '\0';
	return (s1);
}
