/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_farmdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 22:23:38 by afaddoul          #+#    #+#             */
/*   Updated: 2019/12/28 22:24:16 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
/*
static void	roomdel(void *content)
{
	ft_roomdel((t_room**)&content);
}


static void del(void *content)
{
	t_room *room;
	room = (t_room*)content;
	ft_roomdel(&room);
}
*/

static void	call_del(void *content)
{
	ft_roomdel((t_room**)&content);
}

void		ft_grpdestroy(t_dlist **paths, int path_nb)
{
	int	i;

	if (!paths)
		return ;
	i = 0;
	while (i < path_nb)
	{
		if (paths[i])
			ft_pathdel(&paths[i]);
		i++;
	}
}

static void	dummy_del(void *content)
{
	free(content);
}

int			ft_pathdel(t_dlist **path)
{
	if (!path)
		return (0);
	ft_dlstdel(path, dummy_del);
	*path = NULL;
	return (1);
}

void		ft_farmdel(t_farm *farm)
{
	ft_htdel(&farm->rooms_ht, call_del);
//	ft_dlstdel(&farm->rooms, roomdel);
	ft_grpdestroy(farm->grps[0].path, farm->grps[0].path_nb);
	free(farm->grps[0].path);
	ft_grpdestroy(farm->grps[1].path, farm->grps[1].path_nb);
	free(farm->grps[1].path);
	free(farm);
}
