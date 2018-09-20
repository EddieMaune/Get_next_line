/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 12:31:53 by emaune            #+#    #+#             */
/*   Updated: 2018/06/28 12:40:53 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strcmp(const char *s1, const char *s2)
{
	size_t	len;

	len = ft_strlen(s1) >= ft_strlen(s2) ? ft_strlen(s1) : ft_strlen(s2);
	return (ft_memcmp(s1, s2, len));
}
