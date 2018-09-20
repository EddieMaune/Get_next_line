/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 10:59:09 by emaune            #+#    #+#             */
/*   Updated: 2018/06/29 13:24:49 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_digits(int n)
{
	int			len;

	len = 0;
	if (n < 0)
		len++;
	if (!n)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char		*number;
	int			i;
	int			has_sign;

	i = count_digits(n) - 1;
	has_sign = 0;
	if (!(number = ft_strnew(count_digits(n))))
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n *= -1;
		has_sign = 1;
	}
	while (i >= 0)
	{
		number[i] = n % 10 + 48;
		n /= 10;
		i--;
	}
	if (has_sign)
		number[0] = '-';
	return (number);
}
