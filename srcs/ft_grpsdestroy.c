/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grpsdestroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 16:48:22 by afaddoul          #+#    #+#             */
/*   Updated: 2019/12/29 16:55:17 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	dummy_del(void *content)
{
	ft_memdel((void**)&content);
}

int			ft_pathdel(t_dlist **path)
{
	if (!path)
		return (0);
	ft_dlstdel(path, dummy_del);
	*path = NULL;
	return (1);
}

void		ft_grpdestroy(t_dlist **paths, int path_nb)
{
	int	i;

	if (!paths)
		return ;
	i = 0;
	while (i < path_nb)
	{
		if (paths[i])
			ft_pathdel(&paths[i]);
		i++;
	}
}
