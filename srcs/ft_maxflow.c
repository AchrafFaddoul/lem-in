/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maxflow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smouzdah <smouzdah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 01:23:21 by smouzdah          #+#    #+#             */
/*   Updated: 2020/01/12 03:50:49 by smouzdah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_prev_extract(t_dlist *lst, int target)
{
	t_element	*tmp;

	tmp = lst->head;
	while (tmp)
	{
		if ((((t_item*)(tmp->content))->index) == target)
			return ((((t_item*)(tmp->content))->prev));
		tmp = tmp->next;
	}
	return (0);
}

static int		ft_flowvalid(t_farm *farm, t_dlist *lst, int flow, int target)
{
	t_element	*tmp;
	int			ret;

	tmp = GET_ENTRY(target)->edges->head;
	if (flow == target)
		return (0);
	if (target == farm->start->index)
		return (1);
	ret = 1;
	while (tmp)
	{
		if (((t_room*)(tmp->content))->index == flow)
			return (1);
		if (((t_room*)(tmp->content))->flow == target)
			ret =
			(ft_prev_extract(lst, target) == ((t_room*)(tmp->content))->index);
		tmp = tmp->next;
	}
	return (ret);
}

static void		ft_queue_vis_push(t_dlist *queue, t_dlist *lst_vis,
					int index, int prev)
{
	ft_enqueue(queue, ft_elemnew(ft_itemnew(index, prev)));
	ft_dlstpush(lst_vis, ft_elemnew(ft_itemnew(index, prev)));
}

static int		ft_bfs_manager(t_farm *farm, t_dlist *queue,
					t_dlist *lst_vis, int dequeued)
{
	t_element	*tmp;
	int			current;

	tmp = GET_ENTRY(dequeued)->edges->head;
	while (tmp)
	{
		current = ((t_room*)(tmp->content))->index;
		if ((current == farm->end->index) && ((t_room*)(tmp->content))
			->flow == -1)
		{
			ft_dlstdel(&queue, item_del);
			return (1);
		}
		if (!ft_verif_item(lst_vis, current) && current != farm->end->index)
		{
			if (ft_flowvalid(farm, lst_vis,
				((t_room*)(tmp->content))->flow, dequeued))
				ft_queue_vis_push(queue, lst_vis, current, dequeued);
		}
		tmp = tmp->next;
	}
	return (0);
}

int				ft_maxflow(t_farm *farm, int i_grp)
{
	t_dlist		*queue;
	t_dlist		*lst_vis;
	int			dequeued;

	if (!(queue = ft_dlstnew()))
		return (ERROR);
	if (!(lst_vis = ft_dlstnew()))
		return (ERROR);
	ft_queue_vis_push(queue, lst_vis, farm->start->index, 0);
	while (queue->size)
	{
		dequeued = ft_dequeue(queue);
		if (ft_bfs_manager(farm, queue, lst_vis, dequeued))
			return (ft_flowextract(farm, lst_vis, dequeued, i_grp));
	}
	ft_dlstdel(&lst_vis, item_del);
	ft_dlstdel(&queue, item_del);
	return (MAX_FLOW);
}
