/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 23:07:15 by afaddoul          #+#    #+#             */
/*   Updated: 2019/12/29 02:31:26 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstdel(t_dlist **lst, void (*del)(void*))
{
	t_element	*current;
	t_element	*to_del;

	current = (*lst)->head;
	while (current)
	{
		to_del = current;
		current = current->next;
		del(to_del->content);
		ft_memdel((void**)&to_del);
	}
	ft_memdel((void**)lst);
}
