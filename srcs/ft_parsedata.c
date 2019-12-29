/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsedata.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:37:42 by afaddoul          #+#    #+#             */
/*   Updated: 2019/12/29 01:28:52 by afaddoul         ###   ########.fr       */
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
	int 		ret;

	if (!(lst  = ft_dlstnew()))
		return (NULL);
	while ((ret = get_next_line(0, &line)))
	{
		if (ret == -1)
		{
			ft_dlstdel(&lst, dummy_del);
			return (NULL);
		}
		if (!(elm = ft_elemnew(line)))
		{
			ft_dlstdel(&lst, dummy_del);
			return (NULL);
		}
		ft_dlstpush(lst, elm);
	}
	if (!lst->size)
		ft_dlstdel(&lst, dummy_del);
	return (lst);
}

int				ft_parsedata(t_farm *farm)
{
	t_dlist 	*lst;

	if (!(lst = read_input()))
		return (0);
	farm->input = lst;
	if (!ft_farmfill(farm, lst))
		return (0);
	printf("BEF_DEL_KEY%s\n",((t_room*)(farm->rooms->head->content))->key);
	ft_farmdel(farm);
	return (1);
}
