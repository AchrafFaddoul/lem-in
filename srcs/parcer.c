/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 12:05:59 by afaddoul          #+#    #+#             */
/*   Updated: 2019/09/26 16:30:02 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_lst		*store_lines(void)
{
	t_lst	*lst;
	t_lst	*head;
	char	*line;
	int		check;

	check = 0;
	while (get_next_line(0, &line) == 1)
	{
		if (!(lst = add_node(lst, line)))
		{
			free_lst(lst);
			ft_strdel(&line);
			exit(0);
		}
		if (check++ == 0)
			head = lst;
/*
**parse data to db_lsts for rooms and links
*/
		ft_strdel(&line);
	}
	return (head);
}
