/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 12:30:24 by emaune            #+#    #+#             */
/*   Updated: 2018/06/29 12:39:35 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*link;
	t_list	*index;

	link = *alst;
	while (link)
	{
		del(link->content, link->content_size);
		index = link->next;
		free(link);
		link = NULL;
		link = index;
	}
	*alst = NULL;
}
