/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 14:31:39 by ybahlaou          #+#    #+#             */
/*   Updated: 2018/10/29 13:23:43 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*begin;

	list = (*f)(lst);
	lst = lst->next;
	begin = list;
	while (lst != NULL)
	{
		list->next = (*f)(lst);
		list = list->next;
		lst = lst->next;
	}
	list->next = NULL;
	return (begin);
}
