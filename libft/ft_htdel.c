/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htdel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 01:28:57 by afaddoul          #+#    #+#             */
/*   Updated: 2020/01/13 00:29:09 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void		ft_htdel(t_hashtable **ht, void (*del)(void*))
{
	size_t	i;

	i = 0;
	while (i < (*ht)->size)
	{
		if (*((*ht)->entries + i))
			ft_htentrydel((*ht)->entries + i, del);
		i++;
	}
	free((*ht)->entries);
	ft_memdel((void**)ht);
}
