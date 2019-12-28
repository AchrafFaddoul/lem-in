/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstpush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 00:22:23 by afaddoul          #+#    #+#             */
/*   Updated: 2019/12/28 00:22:24 by afaddoul         ###   ########.fr       */
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
