/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstpush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 16:14:27 by afaddoul          #+#    #+#             */
/*   Updated: 2019/10/01 20:11:34 by afaddoul         ###   ########.fr       */
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
