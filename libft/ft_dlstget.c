/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstget.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 21:47:26 by afaddoul          #+#    #+#             */
/*   Updated: 2019/10/15 17:21:23 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
