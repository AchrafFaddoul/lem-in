/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 10:46:47 by afaddoul          #+#    #+#             */
/*   Updated: 2019/12/28 17:20:23 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

# define MAX_FLOW 0
# define UPDATED  1
# define PRINT   -1
# define ERROR   -2

static void dummy_del(void *content)
{
	ft_memdel((void **)(&content));
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

void 			ft_hashmapupdate(t_farm *farm, t_dlist *path)
{
	t_element 	*current;

	current = path->tail;
	ft_flowmark(GET_ENTRY(farm->start->index), ((t_item*)(current->content))->index);
	ft_revflowmark(GET_ENTRY(((t_item*)(current->content))->index), farm->start->index);
	while ((((t_item*)(current->content))->index) != farm->end->index)
	{
		farm->rooms_ht->entries[(((t_item*)(current->content))->index)]->flow = 1;
		ft_flowmark(GET_ENTRY(((t_item*)(current->content))->index), (((t_item*)(current->prev->content))->index));
		ft_revflowmark(GET_ENTRY(((t_item*)(current->prev->content))->index), (((t_item*)(current->content))->index));
		current = current->prev;
	}
}

int 			ft_scorecompute(int path, int node, int ants)
{
	float		result;
	int			ret_val;

	result = ((float)(node + ants) / path);
	ret_val = (int)result;
	ret_val += (result - ret_val != 0.0f ? 1 : 0);
	return (ret_val);
}


int 			ft_prev(t_dlist *lst_vis, int target)
{
	t_element *tmp;

	tmp = lst_vis->head;
	while (tmp)
	{
		if (((t_item*)(tmp->content))->index == target)
			return (((t_item*)(tmp->content))->prev);
		tmp = tmp->next;
	}
	return (-1);
}

int				ft_pathextract(t_farm *farm, t_dlist *lst_vis, t_dlist *standby, int i_grp, int dequeued)
{
	t_dlist 	*path;
	t_item 		*item;
	t_element	*elm;
	long long	ret;

	standby = NULL;
	path = ft_dlstnew();
	if (!path)
		return (ERROR);
	item = ft_itemnew(farm->end->index, -1);
	elm  = ft_elemnew((t_item*)item);
	ft_dlstpush(path, elm);
	while (dequeued != farm->start->index)
	{
		item = ft_itemnew(dequeued, -1);
		elm  = ft_elemnew((t_item*)item);
		ft_dlstpush(path, elm);
		dequeued = ft_prev(lst_vis, dequeued);
	}
	farm->grps[i_grp].node_nb += (path->size - 1);
	ret = ft_scorecompute(farm->grps[i_grp].path_nb + 1, farm->grps[i_grp].node_nb, farm->ants);
	if (ret < farm->grps[i_grp].score)
	{
		farm->grps[i_grp].score = ret;
		ft_hashmapupdate(farm, path);
		farm->grps[i_grp].path[farm->grps[i_grp].path_nb++] = path;
		ft_dlstdel(&lst_vis, dummy_del);
		return (UPDATED);
	}
	ft_dlstdel(&lst_vis, dummy_del);
	return (PRINT);
}

t_dlist			*ft_flowpath(t_farm *farm, int flow)
{
	t_dlist		*path;
	t_element 	*elm;
	t_element 	*tmp;
	t_item 		*item;

	path = ft_dlstnew();
	if (!path)
		return (NULL);
	item = ft_itemnew(farm->end->index, -1);
	elm  = ft_elemnew((t_item*)item);
	ft_dlstpush(path, elm);
	while (flow != farm->start->index)
	{
		item = ft_itemnew(flow, -1);
		elm = ft_elemnew((t_item*)item);
		ft_dlstpush(path, elm);
		tmp = GET_ENTRY(flow)->edges->head;
		while (tmp)
		{
			if (((t_room*)(tmp->content))->index == ((t_room*)(tmp->content))->flow)
				flow = ((t_room*)(tmp->content))->index;
			tmp = tmp->next;
		}
	}
	farm->grps[1].path[farm->grps[1].path_nb++] = path;
	farm->grps[1].node_nb += (path->size - 1);
	return (path);
}

int 		ft_flowextract(t_farm *farm, t_dlist *vis, int dequeued)
{
	t_dlist 	*path;
	t_item 		*item;
	t_element	*elm;
	int			i;
	int			j;

	path = ft_dlstnew();
	if (!path)
		return (ERROR);
	item = ft_itemnew(farm->end->index, -1);
	elm  = ft_elemnew((t_item*)item);
	ft_dlstpush(path, elm);
	while (dequeued != farm->start->index)
	{
		item = ft_itemnew(dequeued, -1);
		elm  = ft_elemnew((t_item*)item);
		ft_dlstpush(path, elm);
		dequeued = ft_prev(vis, dequeued);
	}
	ft_hashmapupdate(farm, path);
	t_element *tmp;

	tmp = GET_ENTRY(farm->end->index)->edges->head;
	while (tmp)
	{
		if (((t_room*)(tmp->content))->flow != -1)
			if (!ft_flowpath(farm, ((t_room*)(tmp->content))->flow))
				return (ERROR);
		tmp = tmp->next;
	}
	farm->grps[1].score = ft_scorecompute(farm->grps[1].path_nb, farm->grps[1].node_nb, farm->ants);
	ft_pathdel(&path);
	i = -1;
	while (++i < farm->grps[1].path_nb)
	{
		j = i;
		while (++j < farm->grps[1].path_nb)
		{
			if (farm->grps[1].path[j]->size < farm->grps[1].path[i]->size)
			{
				path = farm->grps[1].path[i];
				farm->grps[1].path[i] = farm->grps[1].path[j];
				farm->grps[1].path[j] = path;
			}
		}
	}
	return (UPDATED);
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

static void	item_del(void *content)
{
	free(content);
}

int 			ft_bfs(t_farm *farm, int i_grp)
{
	t_dlist		*queue;
	t_dlist 	*lst_vis;
	t_item		*item;
	int			dequeued;
	int 		current_item;
	t_element	*tmp;

	if (!(queue = ft_dlstnew()))
		return (ERROR);
	if (!(lst_vis = ft_dlstnew()))
		return (ERROR);
	item = ft_itemnew(farm->start->index, -1);
	ft_enqueue(queue, ft_elemnew((t_item*)item));
	ft_dlstpush(lst_vis, ft_elemnew((t_item*)ft_itemnew(farm->start->index, -1)));
	while (queue->size)
	{
		dequeued = ft_dequeue(queue);
		tmp = (((t_room*)(farm->rooms_ht->entries[dequeued]->content))->edges)->head;
		while (tmp)
		{
			current_item = ((t_room*)(tmp->content))->index;
			if (current_item == farm->end->index)
			{
				ft_dlstdel(&queue, item_del);
				return (ft_pathextract(farm, lst_vis, NULL, i_grp, dequeued));
			}
			if (!ft_search_item(lst_vis, current_item) && !(farm->rooms_ht->entries[current_item]->flow))
			{
				item = ft_itemnew(current_item, dequeued);
				ft_enqueue(queue, ft_elemnew((t_item*)item));
				ft_dlstpush(lst_vis, ft_elemnew((t_item*)ft_itemnew(current_item, dequeued)));
			}
			tmp = tmp->next;
		}
	}
	ft_dlstdel(&lst_vis, dummy_del);
	ft_dlstdel(&queue, item_del);
	return (MAX_FLOW);
}

int 			ft_flowvalid(t_farm *farm, t_dlist *lst, int flow, int target)
{
	t_element 	*tmp;

	tmp = (((t_room*)(farm->rooms_ht->entries[target]->content))->edges)->head;
	if (flow == target)
		return (0);
	if (target == farm->start->index)
		return (1);
	while (tmp)
	{
		if (((t_room*)(tmp->content))->index == flow)
			return (1);
		if (((t_room*)(tmp->content))->flow == target)
		{
			if (ft_search_item(lst,((t_room*)(tmp->content))->index))
				return (1);
			else
				return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

int 			ft_maxflow(t_farm *farm)
{
	t_dlist		*queue;
	t_dlist 	*lst_vis;
	t_item		*item;
	int 		dequeued;
	int 		current_item;
	t_element	*tmp;

	if (!(queue = ft_dlstnew()))
		return (ERROR);
	if (!(lst_vis = ft_dlstnew()))
		return (ERROR);
	item = ft_itemnew(farm->start->index, -1);
	ft_enqueue(queue, ft_elemnew((t_item*)item));
	ft_dlstpush(lst_vis, ft_elemnew((t_item*)ft_itemnew(farm->start->index, -1)));
	while (queue->size)
	{
		dequeued = ft_dequeue(queue);
		tmp = (((t_room*)(farm->rooms_ht->entries[dequeued]->content))->edges)->head;
		while (tmp)
		{
			current_item = ((t_room*)(tmp->content))->index;
			if ((current_item == farm->end->index) && ((t_room*)(tmp->content))->flow == -1)
			{
				ft_dlstdel(&queue, item_del);
				return (ft_flowextract(farm, lst_vis, dequeued));
			}
			if (!ft_search_item(lst_vis, current_item) && current_item != farm->end->index)
			{
				if (ft_flowvalid(farm, lst_vis, ((t_room*)(tmp->content))->flow, dequeued))
				{
					item = ft_itemnew(current_item, dequeued);
					ft_dlstpush(lst_vis, ft_elemnew((t_item*)ft_itemnew(current_item, dequeued)));
					ft_enqueue(queue, ft_elemnew((t_item*)item));
				}
			}
			tmp = tmp->next;
		}
	}
	ft_dlstdel(&queue, item_del);
	return (MAX_FLOW);
}

t_dlist			**ft_grpnew(size_t size)
{
	t_dlist		**grp;

	grp = (t_dlist**)ft_memalloc(sizeof(t_dlist*) * (int)size);
	if (!grp)
		return (NULL);
	return (grp);
}

void			ft_grpsreverse(t_farm *farm)
{
	farm->grps[0].score = farm->grps[1].score;
	ft_grpdestroy(farm->grps[0].path, farm->grps[0].path_nb);
	farm->grps[0].path_nb = farm->grps[1].path_nb;
	farm->grps[0].path = farm->grps[1].path;
	farm->grps[1].path = ft_grpnew(farm->start->edges->size);
	farm->grps[1].path_nb = 0;
	farm->grps[1].score = 9223372036854775807;
	farm->grps[1].node_nb = 0;
}

int				ft_maxflowcaller(t_farm *farm)
{
	int 		ret;

	ret = ft_maxflow(farm);
	if (ret == ERROR || ret == MAX_FLOW)
		return (ret);
	return (1);
}

int 			ft_bfsmanager(t_farm *farm)
{
	int 		ret;

	farm->grps[0].score = 9223372036854775807;
	farm->grps[0].path = ft_grpnew(GET_ENTRY(((t_room*)(farm->start))->index)->edges->size);
	ret = ft_bfs(farm, 0);
	if (ret == ERROR)
		return (0);
	farm->grps[1].path = ft_grpnew(farm->start->edges->size);
	farm->grps[1].score = 9223372036854775807;
	while ((ret = ft_maxflowcaller(farm)) != ERROR)
	{
		if (ret == MAX_FLOW)
		{
			ft_grpdestroy(farm->grps[1].path, farm->grps[1].path_nb);
			return (1);
		}
		if (farm->grps[0].score < farm->grps[1].score)
		{
			ft_grpdestroy(farm->grps[1].path, farm->grps[1].path_nb);
			return (1);
		}
		else
			ft_grpsreverse(farm);
	}
	return (0);
}
