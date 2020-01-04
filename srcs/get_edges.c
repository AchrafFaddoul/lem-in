/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_edges.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 15:37:43 by afaddoul          #+#    #+#             */
/*   Updated: 2020/01/04 16:47:16 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		equ(const void *target, const void *current)
{
	return (target == current);
}

static int		get_type(const char *line)
{
	if ((*line == 'L'))
		return (T_INVALID);
	if ((*line == '#') || (line[0] == '#' && line[1] == '#'))
		return (T_COMMENT);
	return (T_LINKS);
}

static int		search_and_insert(t_farm *farm,
		const char *vertex, const char *neighbor)
{
	t_room	*vertex_room;
	t_room	*neighbor_room;
	int		vx_in;
	int		ng_in;

	if (!(vertex_room = (t_room*)ft_htget(farm->rooms_ht, vertex)))
		return (0);
	if (!(neighbor_room = (t_room*)ft_htget(farm->rooms_ht, neighbor)))
		return (0);
	vx_in = vertex_room->index;
	ng_in = neighbor_room->index;
	if ((ft_dlstget((GET_ENTRY(vx_in))->edges, neighbor_room, equ)))
		if ((ft_dlstget((GET_ENTRY(ng_in))->edges, vertex_room, equ)))
			return (0);
	ft_dlstpush((GET_ENTRY(vx_in))->edges,
			ft_elemnew(ft_roomdup(neighbor_room)));
	((t_room*)((GET_ENTRY(vx_in))->edges->tail->content))->flow = -1;
	ft_dlstpush((GET_ENTRY(ng_in))->edges, ft_elemnew(ft_roomdup(vertex_room)));
	((t_room*)((GET_ENTRY(ng_in))->edges->tail->content))->flow = -1;
	return (1);
}

static t_farm	*del_nodes(char *vertex, char *neighbor)
{
	ft_strdel(&vertex);
	ft_strdel(&neighbor);
	return (NULL);
}

t_farm			*ft_getedges(t_farm *farm, t_element *lst)
{
	char		*vertex;
	char		*neighbor;
	int			ret;

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
			return (del_nodes(vertex, neighbor));
		del_nodes(vertex, neighbor);
		lst = lst->next;
	}
	return (farm);
}
