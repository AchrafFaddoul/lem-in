/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstget.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 21:47:26 by afaddoul          #+#    #+#             */
/*   Updated: 2019/10/07 05:51:19 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				equ(const void *target, const void *current)
{
	if (target == current)
		return (1);
	return (0);
}

void			*ft_dlstget(t_dlist *lst, const void *data,
		int (*equ)(const void*, const void*))
{
	t_element	*elm;

	elm = lst->head;
	while (elm != NULL)
	{
		if (equ(data, elm->content) == 1)
			return (elm->content);
		elm = elm->next;
	}
	return (NULL);
}
