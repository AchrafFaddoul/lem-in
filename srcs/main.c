/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 11:22:34 by afaddoul          #+#    #+#             */
/*   Updated: 2019/09/26 16:18:33 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "lem_in.h"

int			main(void)
{
	t_lst	*lst;

	lst = NULL;
	lst = store_lines();
	while (lst)
	{
		printf("%s\n", lst->line);
		lst = lst->next;
	}
	return (0);
}
