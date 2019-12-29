/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:12:36 by afaddoul          #+#    #+#             */
/*   Updated: 2019/12/29 02:03:24 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

# define T_INSTRUCTION	0
# define T_START		1
# define T_END			2
# define T_COMMENT		3
# define T_VERTEX		4

static int		get_type(const char *line)
{
	if (*line == 'L')
		return (T_INSTRUCTION);
	if (ft_strequ(line, "##start"))
		return (T_START);
	if (ft_strequ(line, "##end"))
		return (T_END);
	if (*line == '#')
		return (T_COMMENT);
	return (T_VERTEX);
}

t_element		*ft_getrooms(t_farm *farm, t_dlist *lst)
{
	t_element	*current;
	t_room		*room;
	int 		ret;

	current = lst->head->next;
	farm->rooms = ft_dlstnew();
	while (current)
	{
		if (!(ret = get_type(current->content)))
			return (NULL);
		if (ret == T_COMMENT)
		{
			current = current->next;
			continue ;
		}
		else if (ret == T_START)
		{
			if (farm->start)
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
			current = current->next;
			if (!(room = ft_roomparse((char*)(current->content))))
				return (NULL);
			farm->end = room;
			ft_dlstpush(farm->rooms, ft_elemnew(room));
		}
		else if (!(room = ft_roomparse((char*)(current->content))))
			return (NULL);
		else
			ft_dlstpush(farm->rooms, ft_elemnew(room));
		current = current ? current->next : NULL;
		if (ft_countof(current->content, '-') == 1)
			break ;
	}
	return (current);
}
