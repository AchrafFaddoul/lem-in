/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roomdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 20:52:16 by afaddoul          #+#    #+#             */
/*   Updated: 2020/01/12 20:10:12 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	entry_del(void *content)
{
	t_room	*room;

	room = (t_room*)content;
	ft_strdel(&room->key);
	ft_memdel((void**)&room->edges);
	ft_roomdel(&room);
}

void		ft_roomdel(t_room **room)
{
	ft_strdel(&(*room)->key);
	if ((*room)->edges)
		ft_dlstdel(&(*room)->edges, &entry_del);
	ft_memdel((void**)room);
}
