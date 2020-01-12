/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:09:53 by afaddoul          #+#    #+#             */
/*   Updated: 2020/01/12 20:02:36 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_element	*ft_iscmd(t_element *current)
{
	if (ft_strequ(((char*)(current->content)), "##start"))
		return (NULL);
	else if (ft_strequ((current->content), "##end"))
		return (NULL);
	return (current);
}

t_element			*ft_antsparser(t_farm *farm, t_dlist *lst)
{
	t_element		*current;

	current = lst->head;
	while (current)
	{
		if (*((char*)(current->content)) == '#')
		{
			if (!ft_iscmd(current))
				return (NULL);
			else
			{
				current = current->next;
				continue ;
			}
		}
		else
		{
			if (!ft_getants(farm, current->content))
				return (NULL);
			current = current ? current->next : NULL;
			break ;
		}
		current = current ? current->next : NULL;
	}
	return (current);
}

int					ft_getants(t_farm *farm, char *line)
{
	if (!ft_isulong(line, '\0'))
		return (0);
	if (!(farm->ants = ft_atol(line)))
		return (0);
	if (farm->ants > MAX_INT)
		return (0);
	return (1);
}
