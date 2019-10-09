/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_farmfill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:44:04 by afaddoul          #+#    #+#             */
/*   Updated: 2019/10/07 09:06:30 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		noderm(t_dlist *lst)
{
	t_element	*to_del;

	to_del = lst->head;
	lst->head = lst->head->next;
	ft_memdel(&to_del->content);
	ft_memdel((void**)&to_del);
}

t_farm			*ft_farmfill(t_farm *farm, t_dlist *lst)
{
	t_element	*current;

	if (!(ft_getants(farm, lst->head->content)))
		return (NULL);
	noderm(lst);
	if (!(current = ft_getrooms(farm, lst)))
		return (NULL);
	if (!(farm->rooms_ht = ft_dlisttoht(farm)))
		return (NULL);
	/*	while (farm->rooms->head)
		{
		ft_putendl(((t_room*)(farm->rooms->head->content))->key);
		farm->rooms->head = farm->rooms->head->next;
		} 
	size_t  i = 0;
	ft_putendl("");
	ft_putendl("");
	ft_putendl("");
	ft_putendl("");
	while (i < farm->rooms_ht->size)
	{
		ft_putendl("----------------------");
		ft_putendl((farm->rooms_ht->entries[i])->key);
		ft_putendl((((t_room*)((farm->rooms_ht->entries[i++])->content))->key));
		ft_putendl("----------------------");
	}
	*/
		if (!(ft_getedges(farm, current)))
			return (NULL);
	return (farm);
}
