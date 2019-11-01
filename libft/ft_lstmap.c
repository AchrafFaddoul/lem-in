/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 16:02:37 by afaddoul          #+#    #+#             */
/*   Updated: 2018/10/23 12:02:31 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *begin;
	t_list *hyper_lst;

	if (!lst)
		return (NULL);
	hyper_lst = (t_list*)malloc(sizeof(t_list));
	hyper_lst = f(lst);
	begin = hyper_lst;
	while (lst->next)
	{
		hyper_lst->next = f(lst->next);
		hyper_lst = hyper_lst->next;
		lst = lst->next;
	}
	return (begin);
}
