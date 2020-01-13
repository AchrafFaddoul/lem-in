/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashmap_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 01:17:47 by afaddoul          #+#    #+#             */
/*   Updated: 2020/01/13 01:21:58 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void call_del(void *content)
{
	ft_roomdel((t_room**)&content);
}

static void nothing(void *element)
{
	(void)element;
}
static void     dummy_del(void *content)
{
	ft_strdel((char **)(&content));
}

static void room_del(void *content)
{
	t_room  *room;

	room = (t_room*)content;
	ft_strdel(&room->key);
	ft_memdel((void**)&room->edges);
	ft_roomdel(&room);
}

void 		ft_hashmap_error(t_farm *farm)
{
	ft_error();
	ft_dlstdel(&farm->input, dummy_del);
	if (farm->rooms_ht)
	{
		ft_htdel(&farm->rooms_ht, call_del);
		if (farm->rooms)
			ft_dlstdel(&farm->rooms, &nothing);
	}
	else
	{
		if (farm->rooms)
			ft_dlstdel(&farm->rooms, room_del);
	}
	exit(1);
}
