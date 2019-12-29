/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maxflow_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smouzdah <smouzdah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 01:30:31 by smouzdah          #+#    #+#             */
/*   Updated: 2019/12/29 01:31:19 by smouzdah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			item_del(void *content)
{
	free(content);
}

void			ft_revflowmark(t_room *room, int value)
{
	t_element	*tmp;

	tmp = room->edges->head;
	while (tmp)
	{
		if (((t_room*)(tmp->content))->index == value)
		{
			if (room->index == ((t_room*)(tmp->content))->flow)
				((t_room*)(tmp->content))->flow = -1;
			else
				((t_room*)(tmp->content))->flow = value;
		}
		tmp = tmp->next;
	}
}

void			ft_flowmark(t_room *room, int value)
{
	t_element	*tmp;

	tmp = room->edges->head;
	while (tmp)
	{
		if (((t_room*)(tmp->content))->index == value)
		{
			if (((t_room*)(tmp->content))->flow == value)
				((t_room*)(tmp->content))->flow = -1;
			else
				((t_room*)(tmp->content))->flow = room->index;
		}
		tmp = tmp->next;
	}
}

void			ft_hashmapupdate(t_farm *farm, t_dlist *path)
{
	t_element	*current;

	current = path->tail;
	ft_flowmark(GET_ENTRY(farm->start->index),
		((t_item*)(current->content))->index);
	ft_revflowmark(GET_ENTRY(((t_item*)(current->content))->index),
		farm->start->index);
	while ((((t_item*)(current->content))->index) != farm->end->index)
	{
		farm->rooms_ht->entries[(((t_item*)(current->content))->index)]
			->flow = 1;
		ft_flowmark(GET_ENTRY(((t_item*)(current->content))->index),
			(((t_item*)(current->prev->content))->index));
		ft_revflowmark(GET_ENTRY(((t_item*)(current->prev->content))->index),
			(((t_item*)(current->content))->index));
		current = current->prev;
	}
}
