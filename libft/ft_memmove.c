/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 10:41:29 by emaune            #+#    #+#             */
/*   Updated: 2018/06/28 12:16:18 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tdst;
	char	*tsrc;

	tdst = (char*)dst;
	tsrc = (char*)src;
	if (dst > src)
	{
		while (len > 0)
		{
			len--;
			tdst[len] = tsrc[len];
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
