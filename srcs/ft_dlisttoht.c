/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlisttoht.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 10:46:47 by afaddoul          #+#    #+#             */
/*   Updated: 2019/10/04 11:25:21 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_hashtable			*ft_dlisttoht(t_dlist *rooms)
{
	t_hashtable		*ht;
	t_element		*current;
	t_room			*room;
	t_htentry		*entry;

	ht = ft_htnew(rooms->size);
	if (ht == NULL)
		return (NULL);
	current = rooms->head;
	while (current != NULL)
	{
		room = (t_room*)current->content;
		if (!(entry = ft_htentrynew(room->key, (void*)room)))
		{
			// del all hash table
			break ;
		}
		ft_htinsert(ht, entry);
		current = current->next;
	}
	return (ht);
}
