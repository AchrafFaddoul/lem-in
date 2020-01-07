/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:12:36 by afaddoul          #+#    #+#             */
/*   Updated: 2020/01/05 01:25:47 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		get_type(const char *line)
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

t_element		*ft_getrooms(t_farm *farm, t_element *elm)
{
	t_element	*current;
	t_room		*room;
	int 		ret;

	current = elm;
	farm->rooms = ft_dlstnew();
	printf("IN\n");
	while (current)
	{
		printf("ADR->|%p|\n", (char*)current->content);
		printf("ROOM->|%s|\n", (char*)current->content);
		if (!(ret = get_type(current->content)))
			return (NULL);
		if (ret == T_CMT)
		{
			current = current->next;
			continue ;
		}
		else if (ret == T_START)
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
			printf("CHECK\n");
			if (farm->end)
				return (NULL);
			if (!current->next)
				return (NULL);
			current = current->next;
			if (!(room = ft_roomparse((char*)(current->content))))
				return (NULL);
			farm->end = room;
			ft_dlstpush(farm->rooms, ft_elemnew(room));
			printf("CHECK\n");
		}
		else if (!(room = ft_roomparse((char*)(current->content))))
		{
			if (ft_countof(current->content, '-') == 1)
				break ;
			return (NULL);
		}
		else
			ft_dlstpush(farm->rooms, ft_elemnew(room));
		printf("CHECK\n");
		current = current ? current->next : NULL;
		if (ft_countof(current->content, '-') == 1)
			break ;
		printf("CHECK\n");
	}
	printf("OUT\n");
	return (current);
}
