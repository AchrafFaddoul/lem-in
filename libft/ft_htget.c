/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htget.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 19:17:42 by ybahlaou          #+#    #+#             */
/*   Updated: 2019/10/02 19:54:16 by ybahlaou         ###   ########.fr       */
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

void			*ft_htget(t_hashtable *ht, const char *key)
{
	size_t  index;
	size_t	start;

	index = compute_hash(key) % ht->size;
	start = index;
	while (1)
	{
		if (ht->entries[index] && ft_strequ(ht->entries[index]->key, key))
			return (ht->entries[index]->content);
		index++;
		if (index == start)
			break ;
		if (index == ht->size)
			index = 0;
	}
	return (NULL);
}