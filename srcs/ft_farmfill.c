/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_farmfill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:44:04 by afaddoul          #+#    #+#             */
/*   Updated: 2019/12/29 15:33:59 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_farm			*ft_farmfill(t_farm *farm, t_dlist *lst)
{
	t_element	*current;

	if (!(ft_getants(farm, lst->head->content)))
		return (NULL);
	printf("wa3(1)\n");
	if (!(current = ft_getrooms(farm, lst)))
		return (NULL);
	printf("wa3(2)\n");
	if (!(farm->rooms_ht = ft_dlisttoht(farm)))
		return (NULL);
	printf("wa3(3)\n");
	if (!(ft_getedges(farm, current)))
		return (NULL);
	printf("wa3(4)\n");
	if (!ft_maxflow_manager(farm))
		return (NULL);
	printf("wa3(5)\n");
	ft_putinstructions(farm);
	printf("wa3(6)\n");
	return (farm);
}
