/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_farmfill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:44:04 by afaddoul          #+#    #+#             */
/*   Updated: 2020/01/12 20:40:12 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_isgraphvld(t_farm *farm)
{
	int			ret;

	ret = 0;
	return (ret = (!farm->start || !farm->end) ? ret : 1);
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

static void 	destroy_entries(t_hashtable *ht)
{
	size_t		i;

	i = 0;
	if (!ht)
		return ;
	while (i < ht->size)
	{
		if (ht->entries[i])
		{
			ft_strdel(&(ht->entries[i])->key);
			room_del((ht->entries[i])->content);
			ft_memdel((void**)ht->entries);
		}
		i++;
	}
	free(ht->entries);
	ft_memdel((void**)ht);
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
	if (!(farm->rooms_ht = ft_dlisttoht(farm)))
	{
		ft_error();//F3
		ft_dlstdel(&farm->input, dummy_del);
		if (farm->rooms)
			ft_dlstdel(&farm->rooms, room_del);
		destroy_entries(farm->rooms_ht);
		exit(1);
	}
	if (!current)
		return (NULL);
	if (!(ft_getedges(farm, current)))
		return (NULL);
	if (!ft_maxflow_manager(farm))
		return (NULL);
	if (!ft_putinstructions(farm))
		return (NULL);
	return (farm);
}
