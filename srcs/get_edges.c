/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_edges.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 15:37:43 by afaddoul          #+#    #+#             */
/*   Updated: 2019/12/24 22:57:56 by smouzdah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

# define T_INVALID  	0
# define T_COMMENT      1
# define T_LINKS	2

static int		equ(const void *target, const void *current)
{
	return (target == current);
}

static 	int 	get_type(const char *line)
{
	if ((*line == 'L') || ft_strnequ(line, "##", 2))
		return (T_INVALID);
	if ((*line == '#'))
		return (T_COMMENT);
	return (T_LINKS);
}

t_room 			*ft_roomdup(t_room *room)
{
	t_room 		*new_room;

	new_room = (t_room*)ft_memalloc(sizeof(t_room));
	if (!new_room)
		return (NULL);
	room->key = 
}

static int		search_and_insert(t_farm *farm,
		const char *vertex, const char *neighbor)
{
	t_room	*vertex_room;
	t_room	*neighbor_room;
	int 	vx_in;
	int 	ng_in;

	if (!(vertex_room = (t_room*)ft_htget(farm->rooms_ht, vertex)))
		return (0);
	if (!(neighbor_room = (t_room*)ft_htget(farm->rooms_ht, neighbor)))
		return (0);
	vx_in = vertex_room->index;
	ng_in = neighbor_room->index;
	if ((ft_dlstget(((t_room*)(farm->rooms_ht->entries[vx_in]->content))->edges, neighbor_room, equ)))
		if ((ft_dlstget(((t_room*)(farm->rooms_ht->entries[ng_in]->content))->edges, vertex_room, equ)))
			return (0);
	ft_dlstpush(((t_room*)(farm->rooms_ht->entries[vx_in]->content))->edges, ft_elemnew(neighbor_room));
	printf("index:%d ADR:%p\n", vx_in , ((t_room*)(((t_room*)(farm->rooms_ht->entries[vx_in]->content))->edges->tail->content)));
	((t_room*)(((t_room*)(farm->rooms_ht->entries[vx_in]->content))->edges->tail->content))->flow = -1;
	ft_dlstpush(((t_room*)(farm->rooms_ht->entries[ng_in]->content))->edges, ft_elemnew(vertex_room));
	printf("index:%d ADR:%p\n", ng_in, ((t_room*)(((t_room*)(farm->rooms_ht->entries[ng_in]->content))->edges->tail->content)));
	((t_room*)(((t_room*)(farm->rooms_ht->entries[ng_in]->content))->edges->tail->content))->flow = -1;
	return (1);
}

t_farm 			*ft_getedges(t_farm *farm, t_element *lst)
{
	char		*vertex;
	char		*neighbor;
	int 		ret;

	while (lst)
	{
		if (!(ret = get_type((char*)(lst->content))))
			return (NULL);
		if (ret == T_COMMENT)
		{
			lst = lst->next;
			continue ;
		}
		if (!ft_edgesparse((char*)(lst->content), &vertex, &neighbor))
			return (NULL);
		if (!(search_and_insert(farm, vertex, neighbor)))
		{
			ft_strdel(&vertex);
			ft_strdel(&neighbor);
			return (NULL);
		}
		ft_strdel(&vertex);
		ft_strdel(&neighbor);
		lst = lst->next;
	}
	return (farm);
}
