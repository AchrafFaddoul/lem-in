/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 10:46:47 by afaddoul          #+#    #+#             */
/*   Updated: 2019/12/16 15:56:59 by smouzdah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void dummy_del(void *content)
{
	ft_memdel((void **)(&content));
}

int			ft_search_item(t_dlist *lst, int target)
{
	t_element 	*tmp;

	tmp = lst->head;
	while (tmp)
	{
		if ((((t_item*)(tmp->content))->index) == target)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int 			ft_ismatched(t_room *room, t_dlist *lst_vis)
{
	t_element 	*tmp1;
	t_element 	*tmp2;

	tmp1 = room->edges->head;
	while (tmp1)
	{
		tmp2 = lst_vis->head;
		while (tmp2)
		{
			if (((t_item*)(tmp2->content))->index == room->index)
				break ;
			if (((t_item*)(tmp1->content))->index == ((t_item*)(tmp2->content))->index)
				return (((t_item*)(tmp1->content))->index);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (-1);
}

int				ft_pathextract(t_farm *farm, t_dlist *lst_vis)
{
	t_dlist 	*path;
	t_item 		*item;
	t_element	*elm;
	int 		ret;

	path = ft_dlstnew();
	if (!path)
		return (0);
	item = ft_itemnew(farm->end->index);
	elm  = ft_elemnew((t_item*)item);
	ft_dlstpush(path, elm);
	while (!((ret = ft_ismatched(GET_ENTRY(((t_item*)(path->tail->content))->index), lst_vis))
				== farm->start->index))
	{
		item = ft_itemnew(ret);
		elm  = ft_elemnew((t_item*)item);
		ft_dlstpush(path, elm);
	}
	//update with path lst
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
			if (current_item == farm->end->index)
			{
				ft_pathextract(farm, lst_vis);
				return (1);
			}
			if (!ft_search_item(lst_vis, current_item) && !(farm->rooms_ht->entries[current_item]->flow))
			{
				item = ft_itemnew(current_item);
				elm  = ft_elemnew((t_item*)item);
				ft_enqueue(queue, elm);
				ft_dlstpush(lst_vis, elm);
			}
			tmp = tmp->next;
		}
	}
	ft_dlstdel(&lst_vis, dummy_del);
	return (0);
}
