/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putinstructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 23:13:45 by afaddoul          #+#    #+#             */
/*   Updated: 2019/12/22 00:06:35 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_simulation		**ft_simdestroy(t_simulation **sim_arr, size_t size)
{
	size_t 			i;

	i = 0;
	while (i < size)
	{
		free(sim_arr[i]);
		i++;
	}
	free(sim_arr);
	return (NULL);
}

t_simulation		**ft_simnew(t_farm *farm)
{
	t_simulation 	**sim_arr;
	size_t			size;
	size_t 			i;

	i = 0;
	size = farm->grps[0].path_nb;
	sim_arr = (t_simulation**)ft_memalloc(sizeof(t_simulation*) * size);
	if (!sim_arr)
		return (NULL);
	while (i < size)
	{
		sim_arr[i] = (t_simulation*)ft_memalloc(sizeof(t_simulation*));
		if (!sim_arr[i])
			return (ft_simdestroy(sim_arr, size));
		i++;
	}
	return (sim_arr);
}

static void			ft_structinit(t_farm *farm, t_simulation **sim_arr)
{
	size_t			i;
	size_t 			size;

	i = 0;
	size = (size_t)farm->grps[0].path_nb;
	while (i < size)
	{
		sim_arr[i]->node_nb = farm->grps[0].path[i]->size;
		i++;
	}
}

static int			ft_minlen(t_farm *farm, t_simulation **sim_arr)
{
	size_t			size;
	int 			min_len;
	int 			target;
	size_t 			i;

	i = 0;
	min_len = 2147483647;
	target = 2147483647;
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

t_simulation 		**ft_simulation(t_farm *farm)
{
	t_simulation 	**sim_arr;
	t_dlist			**path;
	size_t 			i;
	long long		ants_nb;

	i = 0;
	ants_nb = farm->ants;
	sim_arr = ft_simnew(farm);
	if (!sim_arr)
		return (sim_arr);
	path = farm->grps[0].path;
	ft_structinit(farm, sim_arr);
	while (ants_nb)
	{
		i = ft_minlen(farm, sim_arr);
		sim_arr[i]->node_nb++;
		sim_arr[i]->ants_nb++;
		ants_nb--;
	}
	i = -1;
	while ((int)(++i) < farm->grps[0].path_nb)
	{
		printf("%d\n", sim_arr[i]->ants_nb);
	}
	return (sim_arr);
}

static t_node		**ft_pathsdestroy(t_node **paths, size_t size)
{
	size_t			i;

	i = 0;
	while (i < size)
	{
		free(paths[i]);
		i++;
	}
	free(paths);
	return (NULL);

}

static void			ft_pathfiller(t_farm *farm, t_node **path, size_t i)
{
	t_element		*tmp;
	int 			j;

	j = 1;
	tmp = farm->grps[0].path[i]->tail;
	printf("END:%s\n", (GET_ENTRY((((t_item*)(tmp->content)))->index))->key);
	while (tmp)
	{
		path[i][j].room = (GET_ENTRY((((t_item*)(tmp->content)))->index))->key;
		tmp = tmp->prev;
		j++;
	}
}

t_node 				**ft_pathsnew(t_farm *farm, t_simulation **sim_arr)
{
	size_t			size;
	size_t 			i;
	t_node 			**paths;

	i = 0;
	size = farm->grps[0].path_nb;
	paths = (t_node**)ft_memalloc(sizeof(t_node*) * size);
	if (!paths)
		return (NULL);
	while (i < size)
	{
		paths[i] = (t_node*)ft_memalloc(sizeof(t_node) * (farm->grps[0].path[i]->size + 1));
		if (!paths[i])
			return (ft_pathsdestroy(paths, size));
		paths[i][0].ants = sim_arr[i]->ants_nb;
		ft_pathfiller(farm, paths, i);
		i++;
	}
	return (paths);
}

int	 				ft_putinstructions(t_farm *farm)
{
	t_simulation 	**sim_arr;
	t_node 			**paths;

	sim_arr = ft_simulation(farm);
	if (!sim_arr)
		return (0);
	if (!(paths = ft_pathsnew(farm, sim_arr)))
		return (0);
	int i = 0;
	size_t j;
	while (i < farm->grps[0].path_nb)
	{
		j = 0;
		while (j < farm->grps[0].path[i]->size + 1)
		{
			printf("|%d:", paths[i][j].ants);
			printf("%s|", paths[i][j].room);
			j++;
		}
		printf("\n");
		i++;
	}
	return (1);
}
