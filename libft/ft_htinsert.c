/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htinsert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 21:57:35 by afaddoul          #+#    #+#             */
/*   Updated: 2019/12/29 22:01:17 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long		ft_htinsert(t_hashtable *ht, const t_htentry *entry)
{
	long long	index;
	long long	start;
	long long	gen_code;

	gen_code = compute_hash(entry->key);
	index = gen_code % ht->size;
	start = index;
	if (ht->entries[index] == NULL)
	{
		ht->entries[index] = (t_htentry*)entry;
		return (index);
	}
	while (1)
	{
		if (ht->entries[index] == NULL)
			break ;
		index++;
		if (index == start)
			return (-1);
		if (index == (long long)ht->size)
			index = 0;
	}
	ht->entries[index] = (t_htentry*)entry;
	return (index);
}
