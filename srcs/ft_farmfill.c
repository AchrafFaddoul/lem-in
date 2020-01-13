/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_farmfill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:44:04 by afaddoul          #+#    #+#             */
/*   Updated: 2020/01/13 01:00:11 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_isgraphvld(t_farm *farm)
{
	int			ret;

	ret = 0;
	return (ret = (!farm->start || !farm->end) ? ret : 1);
}

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

t_farm			*ft_farmfill(t_farm *farm, t_dlist *lst)
{
	t_element	*current;

	if (!(current = ft_antsparser(farm, lst)))
	{
		ft_error();//F1
		ft_dlstdel(&farm->input, dummy_del);
		exit(1);
	}
	if (!(current = ft_getrooms(farm, current)))
	{
		ft_error();///F2
		ft_dlstdel(&farm->input, dummy_del);
		if (farm->rooms)
			ft_dlstdel(&farm->rooms, room_del);
		exit(1);
	}
	if (!ft_isgraphvld(farm))
	{
		ft_error();//F2
		ft_dlstdel(&farm->input, dummy_del);
		if (farm->rooms)
			ft_dlstdel(&farm->rooms, room_del);
		exit(1);
	}
	if (!(ft_dlisttoht(farm)))
	{
		ft_error();//F3
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
	if (!current)
	{
		ft_error();//F3
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
	if (!(ft_getedges(farm, current)))
	{
		ft_error();//F3
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
	if (!ft_maxflow_manager(farm))
	{
		ft_error();//F4
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
		if (farm->grps[0].path)
		{
			ft_grpdestroy(farm->grps[0].path, farm->grps[0].path_nb);
			free(farm->grps[0].path);
		}
		if (farm->grps[1].path)
		{
			ft_grpdestroy(farm->grps[1].path, farm->grps[1].path_nb);
			free(farm->grps[1].path);
		}
		exit(1);
	}
	if (!ft_putinstructions(farm))
	{
		ft_error();//F4-
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
		if (farm->grps[0].path)
		{
			ft_grpdestroy(farm->grps[0].path, farm->grps[0].path_nb);
			free(farm->grps[0].path);
		}
		exit(1);
	}

	return (farm);
}
