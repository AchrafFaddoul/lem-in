/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_edges.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 15:37:43 by afaddoul          #+#    #+#             */
/*   Updated: 2019/10/15 17:44:17 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

# define T_INVALID  	0
# define T_COMMENT      1
# define T_LINKS	2

static int		equ(const void *target, const void *current)
{
	if (target == current)
		return (1);
	return (0);
}

static 	int 	get_type(const char *line)
{
	if ((*line == 'L') || ft_strnequ(line, "##", 2))
		return (T_INVALID);
	if ((*line == '#'))
		return (T_COMMENT);
	return (T_LINKS);
}

static int		search_and_insert(t_farm *farm,
		const char *vertex, const char *neighbor)
{
	t_room	*vertex_room;
	t_room	*neighbor_room;
	int 	vx_in;
	int 	ng_in;

	printf("head of the function\n");
	if (!(vertex_room = (t_room*)ft_htget(farm->rooms_ht, vertex)))
		return (0);
	if (!(neighbor_room = (t_room*)ft_htget(farm->rooms_ht, neighbor)))
		return (0);
	vx_in = vertex_room->index;
	ng_in = neighbor_room->index;
	printf("vx:%d---%s\n", vx_in, vertex_room->key);
	printf("ng:%d---%s\n", ng_in, neighbor_room->key);
	if ((ft_dlstget(((t_room*)(farm->rooms_ht->entries[vx_in]->content))->edges, neighbor_room, equ)))
		return (0);
	if ((ft_dlstget(((t_room*)(farm->rooms_ht->entries[ng_in]->content))->edges, vertex_room, equ)))
		return (0);
	ft_dlstpush(((t_room*)(farm->rooms_ht->entries[vx_in]->content))->edges, (t_element*)vertex_room);
	printf("tail of the function\n");
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
		printf("VX:%s---NG:%s\n", vertex, neighbor);
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
