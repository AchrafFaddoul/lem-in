/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 17:07:38 by afaddoul          #+#    #+#             */
/*   Updated: 2019/12/29 21:54:53 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				del(void *content)
{
	ft_strdel((char**)&content);
}

t_simulation		**ft_simdestroy(t_simulation **sim_arr, size_t size)
{
	size_t			i;

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
	t_simulation	**sim_arr;
	size_t			size;
	size_t			i;

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
	size_t			size;

	i = 0;
	size = (size_t)farm->grps[0].path_nb;
	while (i < size)
	{
		sim_arr[i]->node_nb = farm->grps[0].path[i]->size;
		i++;
	}
}

t_simulation		**ft_simulation(t_farm *farm)
{
	t_simulation	**sim_arr;
	t_dlist			**path;
	size_t			i;
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
	return (sim_arr);
}
