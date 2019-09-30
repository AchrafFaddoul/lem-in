/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstpush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 16:14:27 by afaddoul          #+#    #+#             */
/*   Updated: 2019/09/30 11:21:41 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstpush(t_dlist *lst, t_element *elm)
{
	lst->size++;
	if (!lst->head)
	{
		lst->head = elm;
		lst->tail = elm;
		return ;
	}
	lst->tail->next = elm;
	elm->prev = lst->tail;
	lst->tail = elm;
}
