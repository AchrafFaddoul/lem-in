/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 09:41:11 by afaddoul          #+#    #+#             */
/*   Updated: 2019/10/15 17:49:54 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "lem_in.h"

void 		ft_error(void)
{
	write(1, "ERROR\n", 6);
	// exit(0);
}

int			main(void)
{
	t_farm		*farm;
	t_htentry	*entry;
	// t_room		*room;
	size_t		i;

	ft_putendl("hello 1");
	farm = ft_farmnew();
	if (!(ft_parsedata(farm)))
	{
		ft_putendl("hello 2");
		ft_memdel((void**)(&farm));
		ft_error();
	}
	else
	{
		ft_putendl("hello 3");
		i = 0;
		while (i < farm->rooms_ht->size)
		{
			if (farm->rooms_ht->entries[i] != NULL)
			{
				entry = farm->rooms_ht->entries[i];
				printf("%s\n", entry->key);
			}
			i++;
		}
	}
	return (0);
}
