/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htentrydel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:26:30 by ybahlaou          #+#    #+#             */
/*   Updated: 2019/10/02 22:16:24 by ybahlaou         ###   ########.fr       */
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
