/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 05:22:48 by afaddoul          #+#    #+#             */
/*   Updated: 2019/10/07 06:16:01 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_getindex(t_hashtable *ht, const char *key)
{
	size_t 	index;

	index = compute_hash(key) % ht->size;
	return (index);
}
