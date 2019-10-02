/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 20:46:50 by ybahlaou          #+#    #+#             */
/*   Updated: 2018/10/29 13:23:28 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list *lst, void *data, int (*cmp)(void*, void*))
{
	while (lst != NULL)
	{
		if ((*cmp)(data, lst->content) == 0)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
