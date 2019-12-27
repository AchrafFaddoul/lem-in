/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_farmfill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smouzdah <smouzdah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:44:04 by afaddoul          #+#    #+#             */
/*   Updated: 2019/12/27 18:51:36 by smouzdah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
/*
static void 		print_data(t_farm *farm)
{
	size_t i = 0;
	while (i < farm->rooms_ht->size)
	{
		printf("\nHT_KEY:%s\n|", farm->rooms_ht->entries[i]->key);
		printf("\nHT_index:%zu\n|", i);
		while ((((t_room*)(farm->rooms_ht->entries[i]->content))->edges)->head)
		{
			printf("---->%s\n", ((t_room*)(((((t_room*)(farm->rooms_ht->entries[i]->content))->edges)->head)->content))->key);

			(((t_room*)(farm->rooms_ht->entries[i]->content))->edges)->head = (((t_room*)(farm->rooms_ht->entries[i]->content))->edges)->head->next;
		}
		i++;
	}
}
*/
t_farm			*ft_farmfill(t_farm *farm, t_dlist *lst)
{
	t_element	*current;

	if (!(ft_getants(farm, lst->head->content)))
		return (NULL);
	if (!(current = ft_getrooms(farm, lst)))
		return (NULL);
	if (!(farm->rooms_ht = ft_dlisttoht(farm)))
		return (NULL);
	if (!(ft_getedges(farm, current)))
		return (NULL);
	if (!ft_bfsmanager(farm))
		return (NULL);
	//printf("========>score:%lld\n", farm->grps[0].score);
	ft_putinstructions(farm);
	return (farm);
}
