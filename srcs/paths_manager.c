/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 17:26:11 by afaddoul          #+#    #+#             */
/*   Updated: 2020/01/04 13:09:34 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int					ft_minlen(t_farm *farm, t_simulation **sim_arr)
{
	size_t			size;
	long long		min_len;
	long long 		target;
	size_t			i;

	i = 0;
	min_len = 3147483647;
	target = 3147483647;
	size = (size_t)farm->grps[0].path_nb;
	while (i < size)
	{
		if (sim_arr[i]->node_nb < min_len)
		{
			target = i;
			min_len = sim_arr[i]->node_nb;
		}
		i++;
	}
	return (target);
}

t_node				**ft_pathsdestroy(t_node **paths, size_t size)
{
	size_t			i;

	i = 0;
	while (i < size)
	{
		ft_memdel((void**)&paths[i]);
		i++;
	}
	ft_memdel((void**)&paths);
	return (NULL);
}

static void			ft_pathfiller(t_farm *farm, t_node **path, size_t i)
{
	t_element		*tmp;
	int				j;

	j = 1;
	tmp = farm->grps[0].path[i]->tail;
	while (tmp)
	{
		path[i][j].room = (GET_ENTRY((((t_item*)(tmp->content)))->index))->key;
		tmp = tmp->prev;
		j++;
	}
}

size_t				ft_paths_nb(size_t size, t_simulation **sim_arr)
{
	size_t			i;

	i = 0;
	while (i < size)
	{
		if (sim_arr[i][0].ants_nb == 0)
			break ;
		i++;
	}
	return (i);
}

t_node				**ft_pathsnew(t_farm *farm, t_simulation **sim_arr)
{
	size_t			size;
	size_t			i;
	t_node			**paths;

	i = ft_paths_nb(farm->grps[0].path_nb, sim_arr);
	farm->paths_nb = i;
	size = i;
	i = 0;
	paths = (t_node**)ft_memalloc(sizeof(t_node*) * size);
	if (!paths)
		return (NULL);
	while (i < size)
	{
		paths[i] = (t_node*)ft_memalloc(sizeof(t_node) *
				(farm->grps[0].path[i]->size + 1));
		if (!paths[i])
			return (ft_pathsdestroy(paths, farm->paths_nb));
		paths[i][0].ants = sim_arr[i]->ants_nb;
		ft_pathfiller(farm, paths, i);
		i++;
	}
	return (paths);
}
