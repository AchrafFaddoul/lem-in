/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 10:46:47 by afaddoul          #+#    #+#             */
/*   Updated: 2019/10/04 22:30:58 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_search_item(t_element *lst, int target)
{
	t_element 	*tmp;

	tmp = lst;
	while (tmp)
	{
		if ((((t_room*)(tmp->content))->index) == target)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int 			bfs(t_farm *farm)
{
	t_dlist		*queue;
	t_dlist 	*lst_vis;
	t_element	*elm;
	t_item		*item;
	int 		current_item;
	t_element	*tmp;

	if (!(queue = ft_dlstnew()))
		return (0);
	if (!(lst_vis = ft_dlstnew()))
		return (0);
	item = ft_itemnew(farm->start->index);
	elm  = ft_elemnew((t_item*)item);
	ft_enqueue(queue, elm);
	ft_dlstpush(lst_vis, elm);
	while (queue->size)
	{
		current_item = ft_dequeue(queue);
		tmp = (((t_room*)(farm->rooms_ht->entries[current_item]->content))->edges)->head;
		while (tmp)
		{
			current_item = ((t_room*)(tmp->content))->index;
			if (!ft_search_item(tmp, current_item))
			{
				item = ft_itemnew(current_item);
				elm  = ft_elemnew((t_item*)item);
				ft_enqueue(queue, elm);
				ft_dlstpush(lst_vis, elm);
			}
			tmp = tmp->next;
		}
	}
	return (1);
}
