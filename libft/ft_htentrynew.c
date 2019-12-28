/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htentrynew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 15:57:00 by afaddoul          #+#    #+#             */
/*   Updated: 2019/12/28 15:57:03 by afaddoul         ###   ########.fr       */
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
