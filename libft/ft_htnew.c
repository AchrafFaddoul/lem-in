/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:08:35 by ybahlaou          #+#    #+#             */
/*   Updated: 2019/10/02 19:29:51 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_hashtable		*ft_htnew(size_t size)
{
	t_hashtable *ht;

	if (size == 0)
		return (NULL);
	ht = (t_hashtable*)ft_memalloc(sizeof(t_hashtable));
	if (ht != NULL)
	{
		ht->size = size;
		ht->entries = (t_htentry**)ft_memalloc(sizeof(t_htentry*) * size);
		if (ht->entries == NULL)
			ft_memdel((void**)&ht);
	}
	return (ht);
}
