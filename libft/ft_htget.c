/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htget.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 14:53:01 by afaddoul          #+#    #+#             */
/*   Updated: 2020/01/13 01:42:14 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			compute_hash(const char *key)
{
	const int	p = 31;
	const int	m = 1e9 + 9;
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
	size_t		index;
	size_t		start;
	size_t		count;

	count = 0;
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
		count++;
		if (count == ht->size)
			return (NULL);
	}
	return (NULL);
}
