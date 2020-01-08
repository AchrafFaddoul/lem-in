/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_farmfill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:44:04 by afaddoul          #+#    #+#             */
/*   Updated: 2019/12/29 20:18:51 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_isgraphvld(t_farm *farm)
{
	int 		ret;

	ret = 0;
	return (ret = (!farm->start || !farm->end) ? ret : 1);
}

t_farm			*ft_farmfill(t_farm *farm, t_dlist *lst)
{
	t_element	*current;

	if (!(current = ft_antsparser(farm, lst)))
		return (NULL);
	if (!(current = ft_getrooms(farm, current)))
		return (NULL);
	if (!ft_isgraphvld(farm))
		return (NULL);
	if (!(farm->rooms_ht = ft_dlisttoht(farm)))
		return (NULL);
	if (!(ft_getedges(farm, current)))
		return (NULL);
	if (!ft_maxflow_manager(farm))
		return (NULL);
	if (!ft_putinstructions(farm))
		return (NULL);
	return (farm);
}
