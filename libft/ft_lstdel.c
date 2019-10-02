/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 14:31:25 by ybahlaou          #+#    #+#             */
/*   Updated: 2018/10/29 15:27:16 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*current;
	t_list	*to_del;

	current = *alst;
	while (current != NULL)
	{
		to_del = current;
		(*del)(to_del->content, to_del->content_size);
		current = current->next;
		free(to_del);
	}
	*alst = NULL;
}
