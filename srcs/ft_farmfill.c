/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_farmfill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:44:04 by afaddoul          #+#    #+#             */
/*   Updated: 2019/12/29 01:43:24 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_farm			*ft_farmfill(t_farm *farm, t_dlist *lst)
{
	t_element	*current;

	if (!(ft_getants(farm, lst->head->content)))
		return (NULL);
	if (!(current = ft_getrooms(farm, lst)))
		return (NULL);
	printf("KEY%s\n",((t_room*)(farm->rooms->head->content))->key);
	if (!(farm->rooms_ht = ft_dlisttoht(farm)))
		return (NULL);
	printf("KEY%s\n",((t_room*)(farm->rooms->head->content))->key);
	if (!(ft_getedges(farm, current)))
		return (NULL);
	printf("KEY%s\n",((t_room*)(farm->rooms->head->content))->key);
	if (!ft_maxflow_manager(farm))
		return (NULL);
	printf("KEY%s\n",((t_room*)(farm->rooms->head->content))->key);
	ft_putinstructions(farm);
	printf("KEY%s\n",((t_room*)(farm->rooms->head->content))->key);
	return (farm);
}
