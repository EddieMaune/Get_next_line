/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 10:20:07 by emaune            #+#    #+#             */
/*   Updated: 2018/06/28 10:31:05 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *restrict dst, const void *restrict src,
		int c, size_t n)
{
	size_t			i;
	unsigned char	*tdst;
	unsigned char	*tsrc;
	unsigned char	ch;

	i = 0;
	tdst = (unsigned char*)dst;
	tsrc = (unsigned char*)src;
	ch = (unsigned char)c;
	while (i < n)
	{
		tdst[i] = tsrc[i];
		if (tsrc[i] == ch)
		{
			tdst[i] = tsrc[i];
			return (tdst + i + 1);
		}
		i++;
	}
	return (NULL);
}
