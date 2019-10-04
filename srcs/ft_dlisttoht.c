/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlisttoht.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 10:46:47 by afaddoul          #+#    #+#             */
/*   Updated: 2019/10/04 15:00:36 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	useless_del(void *content)
{
	(void)content;
}

t_hashtable				*ft_dlisttoht(t_farm *farm)
{
	t_element		*current;
	t_room			*room;
	t_htentry		*entry;

	farm->rooms_ht = ft_htnew(farm->rooms->size);
	if (farm->rooms_ht == NULL)
		return (NULL);
	current = farm->rooms->head;
	while (current != NULL)
	{
		room = (t_room*)current->content;
		if (!(entry = ft_htentrynew(room->key, (void*)room)))
		{
			ft_htdel(&farm->rooms_ht, &useless_del);
			break ;
		}
		ft_htinsert(farm->rooms_ht, entry);
		current = current->next;
	}
	return (farm->rooms_ht);
}
