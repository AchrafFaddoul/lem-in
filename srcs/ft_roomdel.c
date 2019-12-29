/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roomdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 20:52:16 by afaddoul          #+#    #+#             */
/*   Updated: 2019/12/29 01:45:50 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void del(void *content)
{
	t_room *room;

	room = (t_room*)content;
	ft_roomdel(&room);
}

void        ft_roomdel(t_room **room)
{
	ft_strdel((char**)&((*room)->key));
	if ((*room)->edges)
		ft_dlstdel(&(*room)->edges, &del);
	ft_memdel((void**)room);
}
