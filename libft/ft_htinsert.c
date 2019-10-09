/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htinsert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:43:37 by ybahlaou          #+#    #+#             */
/*   Updated: 2019/10/07 06:10:58 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					ft_htinsert(t_hashtable *ht, const t_htentry *entry)
{
	size_t	index;
	size_t	start;

	index = compute_hash(entry->key) % ht->size;
	start = index;
	if (ht->entries[index] == NULL)
	{
		ht->entries[index] = (t_htentry*)entry;
		return ;
	}
	while (1)
	{
		if (ht->entries[index] == NULL)
			break ;
		index++;
		if (index == start)
			return ;
		if (index == ht->size)
			index = 0;
	}
	ht->entries[index] = (t_htentry*)entry;
}
