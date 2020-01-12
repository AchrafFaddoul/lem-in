/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:12:36 by afaddoul          #+#    #+#             */
/*   Updated: 2020/01/12 16:58:33 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int			get_type(const char *line)
{
	if (*line == 'L')
		return (T_INSTRUCTION);
	if (ft_strequ(line, "##start"))
		return (T_START);
	if (ft_strequ(line, "##end"))
		return (T_END);
	if (*line == '#')
		return (T_CMT);
	return (T_VERTEX);
}

static t_element	*ft_parsecmd(t_farm *farm, t_element *current,
		t_room *room, int ret)
{
	if (ret == T_START)
	{
		if (farm->start)
			return (NULL);
		if (!current->next)
			return (NULL);
		current = current->next;
		if (!(room = ft_roomparse((char*)(current->content))))
			return (NULL);
		farm->start = room;
		ft_dlstpush(farm->rooms, ft_elemnew(room));
	}
	else if (ret == T_END)
	{
		if (farm->end)
			return (NULL);
		if (!current->next)
			return (NULL);
		current = current->next;
		if (!(room = ft_roomparse((char*)(current->content))))
			return (NULL);
		farm->end = room;
		ft_dlstpush(farm->rooms, ft_elemnew(room));
	}
	return (current);
}

static t_element	*get_vertex(t_farm *farm, t_element *current,
		t_room *room, int ret)
{
	while (current)
	{
		if (!(ret = get_type(current->content)))
			return (NULL);
		if (ret == T_CMT)
		{
			current = current->next;
			continue ;
		}
		else if (!(current = ft_parsecmd(farm, current, room, ret)))
			return (NULL);
		else if (!(room = ft_roomparse((char*)(current->content))))
		{
			if (ft_countof(current->content, '-') == 1)
				break ;
			return (NULL);
		}
		else
			ft_dlstpush(farm->rooms, ft_elemnew(room));
		current = current ? current->next : NULL;
		if (current)
		{
			if (ft_countof(current->content, '-') == 1)
				break ;
		}
		else
			return (NULL);
	}
	return (current);
}

t_element			*ft_getrooms(t_farm *farm, t_element *elm)
{
	t_element		*current;
	static t_room	*room;
	static int		ret;

	current = elm;
	farm->rooms = ft_dlstnew();
	if (!(current = get_vertex(farm, current, room, ret)))
		return (NULL);
	return (current);
}
