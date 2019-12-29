/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roomnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:59:30 by afaddoul          #+#    #+#             */
/*   Updated: 2019/12/29 00:24:54 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*ft_roomnew(char *name)
{
	t_room 	*room;

	room = (t_room*)ft_memalloc(sizeof(t_room));
	if (!room)
		return (NULL);
	room->key = ft_strdup(name);
	if (!room->key)
	{
		ft_memdel((void**)&room);
		return (NULL);
	}
	room->edges = ft_dlstnew();
	printf("here%p\n", room->edges);
	if (room->edges == NULL)
	{
		ft_strdel(&room->key);
		ft_memdel((void**)&room);
	}
	return (room);
}
