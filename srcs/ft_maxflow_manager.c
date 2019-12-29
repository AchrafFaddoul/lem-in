/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maxflow_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smouzdah <smouzdah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 10:46:47 by afaddoul          #+#    #+#             */
/*   Updated: 2019/12/29 20:41:05 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_dlist	**ft_grpnew(size_t size)
{
	t_dlist		**grp;

	grp = (t_dlist**)ft_memalloc(sizeof(t_dlist*) * size);
	if (!grp)
		return (NULL);
	return (grp);
}

static int		ft_grpsreverse(t_farm *farm)
{
	farm->grps[0].score = farm->grps[1].score;
	ft_grpdestroy(farm->grps[0].path, farm->grps[0].path_nb);
	free(farm->grps[0].path);
	farm->grps[0].path = NULL;
	farm->grps[0].path_nb = farm->grps[1].path_nb;
	farm->grps[0].path = farm->grps[1].path;
	if (!(farm->grps[1].path = ft_grpnew(farm->start->edges->size)))
		return (0);
	farm->grps[1].path_nb = 0;
	farm->grps[1].score = 9223372036854775807;
	farm->grps[1].node_nb = 0;
	return (1);
}

int				ft_maxflow_manager(t_farm *farm)
{
	int			ret;

	farm->grps[0].score = 9223372036854775807;
	farm->grps[0].path = ft_grpnew(farm->start->edges->size);
	ret = ft_maxflow(farm, 0);
	if (ret == ERROR)
		return (0);
	farm->grps[1].path = ft_grpnew(farm->start->edges->size);
	farm->grps[1].score = 9223372036854775807;
	while ((ret = ft_maxflow(farm, 1)) != ERROR)
	{
		if (ret == MAX_FLOW || farm->grps[0].score < farm->grps[1].score)
		{
			ft_grpdestroy(farm->grps[1].path, farm->grps[1].path_nb);
			return (1);
		}
		else
		{
			if (!ft_grpsreverse(farm))
				return (0);
		}
	}
	return (0);
}
