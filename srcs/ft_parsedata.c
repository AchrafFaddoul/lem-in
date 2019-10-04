/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsedata.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:37:42 by afaddoul          #+#    #+#             */
/*   Updated: 2019/10/04 15:06:16 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		dummy_del(void *content)
{
	ft_strdel((char **)(&content));
}

t_dlist			*read_input(void)
{
	t_dlist		*lst;
	t_element	*elm;
	char		*line;

	if (!(lst  = ft_dlstnew()))
		return (NULL);
	while (get_next_line(0, &line) == 1)
	{
		if (!(elm = ft_elemnew(line)))
		{
			ft_dlstdel(&lst, dummy_del);
			return (NULL);
		}
		ft_dlstpush(lst, elm);
	}
	return (lst);
}

int				ft_parsedata(t_farm *farm)
{
	t_dlist 	*lst;

	if (!(lst = read_input()))
		return (0);
	if (!(farm = ft_farmfill(farm, lst)))
		return (0);
	if (!(farm->rooms_ht = ft_dlisttoht(farm)))
		return (0);
	for (unsigned long i = 0; i < farm->rooms->size; i++)
	{
		ft_putendl(farm->rooms_ht->entries[i]->key);
	}
	return (1);
}
