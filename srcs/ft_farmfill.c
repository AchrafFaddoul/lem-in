/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_farmfill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:44:04 by afaddoul          #+#    #+#             */
/*   Updated: 2020/01/13 01:35:18 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_isgraphvld(t_farm *farm)
{
	int			ret;

	ret = 0;
	return (ret = (!farm->start || !farm->end) ? ret : 1);
}

t_farm			*ft_farmfill(t_farm *farm, t_dlist *lst)
{
	t_element	*current;

	if (!(current = ft_antsparser(farm, lst)))
		ft_inputdel(farm);
	if (!(current = ft_getrooms(farm, current)))
		ft_rooms_del(farm);
	if (!ft_isgraphvld(farm))
		ft_rooms_del(farm);
	if (!(ft_dlisttoht(farm)))
		ft_hashmap_error(farm);
	if (!current)
		ft_hashmap_error(farm);
	if (!(ft_getedges(farm, current)))
		ft_hashmap_error(farm);
	if (!ft_maxflow_manager(farm))
		ft_maxflow_error(farm);
	if (!ft_putinstructions(farm))
		ft_printing_error(farm);
	return (farm);
}
