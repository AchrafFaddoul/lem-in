/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putinstructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 23:13:45 by afaddoul          #+#    #+#             */
/*   Updated: 2020/01/05 00:47:49 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			ft_antspuller(t_node **paths, int i, int j, int *ants)
{
	paths[i][j + 1].ants = (*ants)++;
	paths[i][j].ants--;
}

void				ft_antsmover(t_farm *farm, t_node **paths,
		int *i, int *done_ants)
{
	static int		ants = 1;
	int				j;

	j = farm->grps[0].path[*i]->size + 1;
	while (--j >= 0)
	{
		if (paths[*i][j].ants != 0)
		{
			if (j == 0)
				ft_antspuller(paths, *i, j, &ants);
			else if (j == (int)farm->grps[0].path[*i]->size)
			{
				(*done_ants)++;
				paths[*i][j].ants = 0;
			}
			else
			{
				paths[*i][j + 1].ants = paths[*i][j].ants;
				paths[*i][j].ants = 0;
			}
		}
	}
}

void				ft_structfiller(t_farm *farm, t_node **paths)
{
	int i;
	int done_ants;

	i = 0;
	done_ants = 0;
	while (done_ants < farm->ants)
	{
		ft_antsmover(farm, paths, &i, &done_ants);
		i++;
		if (i >= (int)farm->paths_nb)
		{
			ft_instruprinter(farm, paths);
			i = 0;
		}
	}
}

int					ft_putinstructions(t_farm *farm)
{
	t_simulation	**sim_arr;
	t_node			**paths;

	sim_arr = ft_simulation(farm);
	if (!sim_arr)
		return (0);
	if (!(paths = ft_pathsnew(farm, sim_arr)))
		return (0);
	ft_inputprinter(farm);
	ft_structfiller(farm, paths);
	ft_pathsdestroy(paths, ft_paths_nb(farm->grps[0].path_nb, sim_arr));
	ft_simdestroy(sim_arr, farm->grps[0].path_nb);
	return (1);
}
