/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htdel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:37:03 by ybahlaou          #+#    #+#             */
/*   Updated: 2019/10/02 20:24:37 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_htdel(t_hashtable **ht, void (*del)(void*))
{
	size_t  i;

	i = 0;
	while (i < (*ht)->size)
	{
		if (*((*ht)->entries + i))
			ft_htentrydel((*ht)->entries + i, del);
		i++;
	}
	*ht = NULL;
}
