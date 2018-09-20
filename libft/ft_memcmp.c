/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 10:59:56 by emaune            #+#    #+#             */
/*   Updated: 2018/06/28 11:05:15 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ts1;
	unsigned char	*ts2;

	i = 0;
	ts1 = (unsigned char*)s1;
	ts2 = (unsigned char*)s2;
	while (i < n)
	{
		if (ts1[i] < ts2[i] || ts1[i] > ts2[i])
			return (ts1[i] - ts2[i]);
		i++;
	}
	return (0);
}
