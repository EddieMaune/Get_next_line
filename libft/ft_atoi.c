/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 12:51:25 by emaune            #+#    #+#             */
/*   Updated: 2018/06/29 13:13:21 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_space(int c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' ||
			c == ' ')
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	int			i;
	int			sign;
	int			number;

	i = 0;
	sign = 1;
	number = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		number = number * 10 + (str[i] - 48);
		i++;
	}
	return ((long)number * sign);
}
