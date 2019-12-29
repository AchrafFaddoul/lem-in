/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roomdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 21:03:23 by afaddoul          #+#    #+#             */
/*   Updated: 2019/12/29 21:04:24 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room			*ft_roomdup(t_room *room)
{
	t_room		*new_room;

	new_room = (t_room*)ft_memalloc(sizeof(t_room));
	if (!new_room)
		return (NULL);
	new_room->key = ft_strdup(room->key);
	if (!(new_room->key))
	{
		ft_memdel((void**)new_room);
		return (NULL);
	}
	new_room->index = room->index;
	new_room->flow = -1;
	return (new_room);
}
