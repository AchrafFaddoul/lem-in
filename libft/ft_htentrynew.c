/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htentrynew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:42:28 by ybahlaou          #+#    #+#             */
/*   Updated: 2019/10/02 20:29:13 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_htentry		*ft_htentrynew(const char *key, const void *content)
{
	t_htentry	*entry;

	entry = (t_htentry*)ft_memalloc(sizeof(t_htentry));
	if (entry != NULL)
	{
		entry->key = ft_strdup(key);
		if (entry->key != NULL)
			entry->content = (void*)content;
		else
			ft_memdel((void**)&entry);
	}
	return (entry);
}
