/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 11:09:04 by emaune            #+#    #+#             */
/*   Updated: 2018/06/28 11:11:27 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strdup(const char *s1)
{
	char		*s;

	s = (char*)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (s)
		ft_memcpy(s, s1, ft_strlen(s1) + 1);
	return (s);
}
