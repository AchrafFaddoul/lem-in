/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_edges.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 15:37:43 by afaddoul          #+#    #+#             */
/*   Updated: 2019/10/07 10:07:14 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

# define T_INVALID  	0
# define T_COMMENT      1
# define T_LINKS	2

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
