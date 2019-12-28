/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_farmfill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:44:04 by afaddoul          #+#    #+#             */
/*   Updated: 2019/12/28 18:21:17 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_farm			*ft_farmfill(t_farm *farm, t_dlist *lst)
{
	t_element	*current;

//	int w = 0;
//	dprintf(2, "f - waa3(%d)\n", w++);
	if (!(ft_getants(farm, lst->head->content)))
		return (NULL);
//	dprintf(2, "f - waa3(%d)\n", w++);
	if (!(current = ft_getrooms(farm, lst)))
		return (NULL);
//	dprintf(2, "f - waa3(%d)\n", w++);
	if (!(farm->rooms_ht = ft_dlisttoht(farm)))
		return (NULL);
//	dprintf(2, "f - waa3(%d)\n", w++);
	if (!(ft_getedges(farm, current)))
		return (NULL);
//	dprintf(2, "f - waa3(%d)\n", w++);
	if (!ft_bfsmanager(farm))
		return (NULL);
//	dprintf(2, "f - waa3(%d)\n", w++);
	ft_putinstructions(farm);
//	dprintf(2, "f - waa3(%d)\n", w++);
	return (farm);
}
