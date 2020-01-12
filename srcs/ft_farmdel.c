/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_farmdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 22:23:38 by afaddoul          #+#    #+#             */
/*   Updated: 2020/01/12 20:06:35 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	call_del(void *content)
{
	ft_roomdel((t_room**)&content);
}

static void	nothing(void *element)
{
	(void)element;
}

void		ft_farmdel(t_farm *farm)
{
	ft_htdel(&farm->rooms_ht, call_del);
	ft_dlstdel(&farm->rooms, &nothing);
	ft_grpdestroy(farm->grps[0].path, farm->grps[0].path_nb);
	free(farm->grps[0].path);
	ft_grpdestroy(farm->grps[1].path, farm->grps[1].path_nb);
	free(farm->grps[1].path);
	free(farm);
}
