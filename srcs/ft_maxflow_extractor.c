/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maxflow_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smouzdah <smouzdah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 01:26:30 by smouzdah          #+#    #+#             */
/*   Updated: 2019/12/29 01:29:33 by smouzdah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_scorecompute(int path, int node,
					int ants)
{
	float		result;
	int			ret_val;

	result = ((float)(node + ants) / path);
	ret_val = (int)result;
	ret_val += (result - ret_val != 0.0f ? 1 : 0);
	return (ret_val);
}

static int		ft_prev(t_dlist *lst_vis, int target)
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

static t_dlist	*ft_flowpath(t_farm *farm, int flow, int i_grp)
{
	t_dlist		*path;
	t_element	*tmp;

	if (!(path = ft_dlstnew()))
		return (NULL);
	ft_dlstpush(path, ft_elemnew(ft_itemnew(farm->end->index, 0)));
	while (flow != farm->start->index)
	{
		ft_dlstpush(path, ft_elemnew(ft_itemnew(flow, 0)));
		tmp = GET_ENTRY(flow)->edges->head;
		while (tmp)
		{
			if (((t_room*)(tmp->content))->index
				== ((t_room*)(tmp->content))->flow)
				flow = ((t_room*)(tmp->content))->index;
			tmp = tmp->next;
		}
	}
	farm->grps[i_grp].path[farm->grps[i_grp].path_nb++] = path;
	farm->grps[i_grp].node_nb += (path->size - 1);
	return (path);
}

static int		ft_updategrp(t_farm *farm, int i_grp, t_dlist *path)
{
	int			i;
	int			j;

	farm->grps[i_grp].score = ft_scorecompute(farm->grps[i_grp].path_nb,
								farm->grps[i_grp].node_nb, farm->ants);
	ft_pathdel(&path);
	i = -1;
	while (++i < farm->grps[i_grp].path_nb)
	{
		j = i;
		while (++j < farm->grps[i_grp].path_nb)
		{
			if (farm->grps[i_grp].path[j]->size <
				farm->grps[i_grp].path[i]->size)
			{
				path = farm->grps[i_grp].path[i];
				farm->grps[i_grp].path[i] = farm->grps[i_grp].path[j];
				farm->grps[i_grp].path[j] = path;
			}
		}
	}
	return (UPDATED);
}

int				ft_flowextract(t_farm *farm, t_dlist *vis,
					int dequeued, int i_grp)
{
	t_dlist		*path;
	t_element	*tmp;

	path = ft_dlstnew();
	if (!path)
		return (ERROR);
	ft_dlstpush(path, ft_elemnew(ft_itemnew(farm->end->index, 0)));
	while (dequeued != farm->start->index)
	{
		ft_dlstpush(path, ft_elemnew(ft_itemnew(dequeued, 0)));
		dequeued = ft_prev(vis, dequeued);
	}
	ft_dlstdel(&vis, item_del);
	ft_hashmapupdate(farm, path);
	tmp = GET_ENTRY(farm->end->index)->edges->head;
	while (tmp)
	{
		if (((t_room*)(tmp->content))->flow != -1)
			if (!ft_flowpath(farm, ((t_room*)(tmp->content))->flow, i_grp))
				return (ERROR);
		tmp = tmp->next;
	}
	return (ft_updategrp(farm, i_grp, path));
}
