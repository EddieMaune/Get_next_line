/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 11:53:49 by emaune            #+#    #+#             */
/*   Updated: 2018/06/28 12:11:26 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *restrict dst, const char *restrict src,
		size_t dstsize)
{
	t_strlcat	v;

	v.dstlen = ft_strlen(dst);
	v.srclen = ft_strlen(src);
	if (!dstsize)
	{
		dst = (char*)src;
		return (v.dstlen);
	}
	else
	{
		v.i = 0;
		while (dst[v.i] && v.i < dstsize)
			v.i++;
		v.dstlen = v.i;
		while (v.i < dstsize - 1 && src[v.i - v.dstlen])
		{
			dst[v.i] = src[v.i - v.dstlen];
			v.i++;
		}
		if (v.dstlen < dstsize)
			dst[v.i] = '\0';
	}
	return (v.srclen + v.dstlen);
}
