/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htentrydel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 01:31:44 by afaddoul          #+#    #+#             */
/*   Updated: 2019/12/28 01:33:19 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_htentrydel(t_htentry **entry, void (*del)(void*))
{
	if (entry == NULL || *entry == NULL)
		return ;
	ft_strdel(&(*entry)->key);
	del((*entry)->content);
	ft_memdel((void**)entry);
}
