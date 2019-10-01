/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsedata.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:37:42 by afaddoul          #+#    #+#             */
/*   Updated: 2019/10/01 20:14:04 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
	return (1);
}
