/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 14:14:14 by emaune            #+#    #+#             */
/*   Updated: 2018/06/28 14:15:22 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strequ(char const *s1, char const *s2)
{
	if (s1 && s2)
	{
		if (!ft_strcmp(s1, s2))
			return (1);
	}
	return (0);
}
