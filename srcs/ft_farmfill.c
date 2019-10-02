/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_farmfill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:44:04 by afaddoul          #+#    #+#             */
/*   Updated: 2019/10/02 11:32:16 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		noderm(t_dlist *lst)
{
	t_element	*to_del;

	to_del = lst->head;
	lst->head = lst->head->next;
	ft_memdel(&to_del->content);
	ft_memdel((void**)&to_del);
}

t_farm			*ft_farmfill(t_farm *farm, t_dlist *lst)
{
	t_element	*current;

	if (!(ft_getants(farm, lst->head->content)))
		return (NULL);
	noderm(lst);
	if (!(current = ft_getrooms(farm, lst)))
		return (NULL);
	//	if (!(get_edges(farm, lst)))
	//		return (NULL);
	return (farm);
}
