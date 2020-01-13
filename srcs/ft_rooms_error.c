/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rooms_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 01:26:56 by afaddoul          #+#    #+#             */
/*   Updated: 2020/01/13 01:35:06 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

void 	ft_inputdel(t_farm *farm)
{
	ft_error();
	ft_dlstdel(&farm->input, dummy_del);
	exit(1);
}

void 	ft_rooms_del(t_farm *farm)
{
	ft_error();
	ft_dlstdel(&farm->input, dummy_del);
	if (farm->rooms)
		ft_dlstdel(&farm->rooms, room_del);
	exit(1);
}
