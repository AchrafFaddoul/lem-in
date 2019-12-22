/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 10:46:47 by afaddoul          #+#    #+#             */
/*   Updated: 2019/12/22 20:02:27 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

# define MAX_FLOW 0
# define UPDATED  1
# define PRINT   -1
# define ERROR   -2

//score managing in BFS

static void dummy_del(void *content)
{
	ft_memdel((void **)(&content));
}



void 			ft_flowmark(t_room *room, int value)
{
	t_element 	*tmp;

	tmp = room->edges->head;
	while (tmp)
	{
		if (((t_room*)(tmp->content))->index == value)
		{
			((t_room*)(tmp->content))->flow = room->index;
			return ;
		}
		tmp = tmp->next;
	}
}

void 			ft_hashmapupdate(t_farm *farm, t_dlist *path)
{
	t_element 	*current;

	current = path->tail;
	ft_flowmark(GET_ENTRY(farm->start->index), ((t_item*)(current->content))->index);
	while ((((t_item*)(current->content))->index) != farm->end->index)
	{
		farm->rooms_ht->entries[(((t_item*)(current->content))->index)]->flow = 1;
		ft_flowmark(GET_ENTRY(((t_item*)(current->content))->index), (((t_item*)(current->prev->content))->index));
		current = current->prev;
	}
}

int 			ft_scorecompute(int path, int node, int ants)
{
	float		result;

	result = ((node + ants) / path);
	result = ((float)(result-(int)result) > 0.0f ? (result + 1) : result);
	return ((int)result);
}

int 			ft_ismatched(t_room *room, t_dlist *lst_vis)
{
	t_element 	*tmp1;
	t_element 	*tmp2;

	tmp2 = room->edges->head;
	tmp1 = lst_vis->head;
	while (tmp1)
	{
		tmp2 = room->edges->head;
		while (tmp2)
		{
			if (((t_item*)(tmp1->content))->index == room->index)
				break ;
			if (((t_room*)(tmp2->content))->index == ((t_item*)(tmp1->content))->index)
				return (((t_room*)(tmp2->content))->index);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (0);
}

int				ft_pathextract(t_farm *farm, t_dlist *lst_vis, int i_grp)
{
	t_dlist 	*path;
	t_item 		*item;
	t_element	*elm;
	long long	ret;

	path = ft_dlstnew();
	if (!path)
		return (ERROR);
	item = ft_itemnew(farm->end->index);
	elm  = ft_elemnew((t_item*)item);
	ft_dlstpush(path, elm);
	while ((ret = ft_ismatched(GET_ENTRY(((t_item*)(path->tail->content))->index), lst_vis)) != farm->start->index)
	{
		item = ft_itemnew(ret);
		elm  = ft_elemnew((t_item*)item);
		ft_dlstpush(path, elm);
	}
	farm->grps[i_grp].node_nb += (path->size -1);
	ret = ft_scorecompute(farm->grps[i_grp].path_nb + 1, farm->grps[i_grp].node_nb, farm->ants);
	if (ret <= farm->grps[i_grp].score)
	{
		farm->grps[i_grp].path_nb++;
		farm->grps[i_grp].score = ret;
		ft_hashmapupdate(farm, path);
		farm->grps[i_grp].path[farm->grps[i_grp].path_nb - 1] = path;
		ft_dlstdel(&lst_vis, dummy_del);
		return (UPDATED);
	}
	ft_dlstdel(&lst_vis, dummy_del);
	return (PRINT);
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

int 			ft_bfs(t_farm *farm, int i_grp)
{
	t_dlist		*queue;
	t_dlist 	*lst_vis;
	t_item		*item;
	int 		current_item;
	t_element	*tmp;

	if (!(queue = ft_dlstnew()))
		return (ERROR);
	if (!(lst_vis = ft_dlstnew()))
		return (ERROR);
	item = ft_itemnew(farm->start->index);
	ft_enqueue(queue, ft_elemnew((t_item*)item));
	ft_dlstpush(lst_vis, ft_elemnew((t_item*)ft_itemnew(farm->start->index)));
	while (queue->size)
	{
		current_item = ft_dequeue(queue);
		tmp = (((t_room*)(farm->rooms_ht->entries[current_item]->content))->edges)->head;
		while (tmp)
		{
			current_item = ((t_room*)(tmp->content))->index;
			if (current_item == farm->end->index)
			{
				//	ft_dlstdel(&queue, dummy_del); prblm here seg
				return (ft_pathextract(farm, lst_vis, i_grp));
			}
			if (!ft_search_item(lst_vis, current_item) && !(farm->rooms_ht->entries[current_item]->flow))
			{
				item = ft_itemnew(current_item);
				ft_enqueue(queue, ft_elemnew((t_item*)item));
				ft_dlstpush(lst_vis, ft_elemnew((t_item*)ft_itemnew(current_item)));
			}
			tmp = tmp->next;
		}
	}
	ft_dlstdel(&lst_vis, dummy_del);
	return (MAX_FLOW);
}

int 			ft_maxflow(t_farm *farm, int i_grp)
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
	item = ft_itemnew(farm->start->index);
	ft_enqueue(queue, ft_elemnew((t_item*)item));
	ft_dlstpush(lst_vis, ft_elemnew((t_item*)ft_itemnew(farm->start->index)));

	while (queue->size)
	{
		dequeued = ft_dequeue(queue);
		tmp = (((t_room*)(farm->rooms_ht->entries[dequeued]->content))->edges)->head;
		while (tmp)
		{
			current_item = ((t_room*)(tmp->content))->index;
			if (current_item == farm->end->index)
			{
				//ft_dlstdel(&queue, dummy_del);   < prblm herey
				return (ft_pathextract(farm, lst_vis, i_grp));
			}
			if (!ft_search_item(lst_vis, current_item) && ((t_room*)(tmp->content))->flow != dequeued)
			{
				item = ft_itemnew(current_item);
				ft_enqueue(queue, ft_elemnew((t_item*)item));
				ft_dlstpush(lst_vis, ft_elemnew((t_item*)ft_itemnew(current_item)));
			}
			tmp = tmp->next;
		}
	}
	//ft_dlstdel(&lst_vis, dummy_del);
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

static void 		ft_farmreset(t_farm *farm)
{
	t_element 		*tmp;
	size_t i;

	i	= 0;
	while (i < farm->rooms_ht->size)
	{
		farm->rooms_ht->entries[i]->flow = 0;
		tmp = (((t_room*)(farm->rooms_ht->entries[i]->content))->edges)->head;
		while (tmp)
		{
			((t_room*)(tmp->content))->flow = -1;
			tmp = tmp->next;
		}
		i++;
	}
}

int 			ft_maxflowcaller(t_farm *farm)
{
	int 		ret;
	ret = ft_maxflow(farm, 1);
	if (ret == ERROR)
		return (-1);
	else if(ret == MAX_FLOW)
		return (1);
	ft_farmreset(farm);
	ft_hashmapupdate(farm, farm->grps[1].path[0]);
	while ((ret = ft_bfs(farm, 1)) != MAX_FLOW && ret != PRINT)
	{
		if (ret == ERROR)
			return (-1);
	}
	return (1);
}

static int 			ft_pathdel(t_dlist *path)
{
	if (path)
		ft_dlstdel(&path, dummy_del);
	else
		return (0);
	return (1);
}
void			ft_grpdestroy(t_dlist **grp, int path_nb)
{
	int			i;

	i = 0;
	while (i < path_nb)
		ft_pathdel(grp[i++]);
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

int 			ft_bfsmanager(t_farm *farm)
{
	int 		ret;

	farm->grps[0].score = 9223372036854775807;
	farm->grps[0].path = ft_grpnew(GET_ENTRY(((t_room*)(farm->start))->index)->edges->size);
	while ((ret = ft_bfs(farm, 0)) != MAX_FLOW)
	{
		if (ret == ERROR)
			return (0);
		else if (ret == PRINT)
			return (1);
	}
	farm->grps[1].path = ft_grpnew(farm->start->edges->size);
	farm->grps[1].score = 9223372036854775807;
	while ((ret = ft_maxflowcaller(farm)) != 0)
	{
		if(ret == -1)
			return (0);
		if (farm->grps[0].score <= farm->grps[1].score)
			return (1);
		else
			ft_grpsreverse(farm);
	}
	//compare scores
	return (0);
}
