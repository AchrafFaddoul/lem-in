/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htinsert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:43:37 by ybahlaou          #+#    #+#             */
/*   Updated: 2019/10/02 19:51:35 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	compute_hash(const char *key)
{
	const int 	p = 31;
	const int 	m = 1e9 + 9;
	size_t		hash_value;
	size_t		p_pow;

	hash_value = 0;
	p_pow = 1;
	while (*key)
	{
		hash_value = (hash_value + (*key - 'a' + 1) * p_pow) % m;
		p_pow = (p_pow * p) % m;
		key++;
	}
	return (hash_value);
}

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
