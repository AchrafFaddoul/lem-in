/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_farmdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 22:23:38 by afaddoul          #+#    #+#             */
/*   Updated: 2019/12/29 02:31:24 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
static void	roomdel(void *content)
{
	ft_roomdel((t_room**)&content);
}

static void chardel(void *content)
{
	ft_strdel((char**)&content);
}
*/
/*
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


static void	dummy_del(void *content)
{
	free(content);
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
	printf("%p\n",farm->rooms);
	ft_htdel(&farm->rooms_ht, call_del);
	printf("%p\n",farm->rooms);
	free(farm->rooms);
	printf("%p\n",farm->rooms);

	ft_grpdestroy(farm->grps[0].path, farm->grps[0].path_nb);
	free(farm->grps[0].path);
	ft_grpdestroy(farm->grps[1].path, farm->grps[1].path_nb);
	free(farm->grps[1].path);
	free(farm);
}







