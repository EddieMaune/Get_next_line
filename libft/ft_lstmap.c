/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 11:49:43 by emaune            #+#    #+#             */
/*   Updated: 2018/06/29 14:09:04 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *index;

	if (!f || !lst)
		return (NULL);
	if (!(index = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	index = f(lst);
	if (lst->next != NULL)
	{
		index->next = ft_lstmap(lst->next, f);
	}
	return (index);
}
