/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_farmdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 22:23:38 by afaddoul          #+#    #+#             */
/*   Updated: 2019/12/29 01:44:31 by afaddoul         ###   ########.fr       */
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
	ft_dlstdel(&farm->rooms, call_del);
//	printf("adr_del:%p\n", farm->rooms);
//	printf("adr_del_head:%p\n", farm->rooms->head);
	//printf("KEY%s\n",((t_room*)(farm->rooms->head->content))->key);
//	ft_memdel((void**)&farm->rooms);
	//ft_memdel((void**)&farm->rooms);
	ft_grpdestroy(farm->grps[0].path, farm->grps[0].path_nb);
	free(farm->grps[0].path);
	ft_grpdestroy(farm->grps[1].path, farm->grps[1].path_nb);
	free(farm->grps[1].path);
	free(farm);
}







/*
	t_element *tmp;

	tmp = farm->rooms->head;
	while (tmp)
	{
	//	printf("%s\n", ((t_room*)(tmp->content))->key);
		printf("EDGES_ADR%p\n",((t_room*)(tmp->content))->edges);
		tmp = tmp->next;
	}
*/
