/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_edgenew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 17:01:50 by afaddoul          #+#    #+#             */
/*   Updated: 2019/10/04 17:04:34 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_edges			*ft_roomnew(char **links)
{
	t_egdes		*edge;

	edge = (t_edge*)ft_memalloc(sizeof(t_edge));
	if (!edge)
		return (NULL);
	edge->vertex = links[0];
	edge->neighbor = links[1];
	return (edge);
}
