/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 10:46:47 by afaddoul          #+#    #+#             */
/*   Updated: 2019/12/29 21:51:13 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_enqueue(t_dlist *lst, t_element *elm)
{
	ft_dlstpush(lst, elm);
}

int				ft_dequeue(t_dlist *lst)
{
	t_element	*to_del;
	t_element	*tmp;
	int			item;

	to_del = lst->head;
	if (lst->size == 1)
	{
		item = ((t_item*)to_del->content)->index;
		item_del((t_item*)to_del->content);
		ft_memdel((void**)&to_del);
		lst->head = NULL;
		lst->tail = NULL;
		lst->size--;
		return (item);
	}
	item = ((t_item*)(to_del->content))->index;
	tmp = lst->head->next;
	item_del((t_item*)to_del->content);
	ft_memdel((void**)&to_del);
	lst->size--;
	lst->head = tmp;
	lst->head->prev = NULL;
	return (item);
}

t_item			*ft_itemnew(int value, int prev)
{
	t_item		*item;

	item = (t_item*)ft_memalloc(sizeof(t_item));
	if (!item)
		return (NULL);
	item->index = value;
	item->prev = prev;
	return (item);
}
