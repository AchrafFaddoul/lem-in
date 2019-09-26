/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 13:35:09 by afaddoul          #+#    #+#             */
/*   Updated: 2019/09/26 16:23:32 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_lst				*add_node(t_lst *head, char *line)
{
	t_lst			*current;
	t_lst			*node;

	if (!(node = ft_memalloc(sizeof(t_lst))))
		return (NULL);
	node->line = ft_strdup(line);
	if (head == NULL)
	{
		node->next = NULL;
		return (node);
	}
	else
	{
		current = head;
		while (current->next)
			current = current->next;
		current->next = node;
		node->next = NULL;
	}
	return (node);
}
