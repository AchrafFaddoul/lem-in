/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremoveat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 00:39:40 by ybahlaou          #+#    #+#             */
/*   Updated: 2019/04/26 00:57:52 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstremoveat(t_list **lst, void (*del)(void*, size_t), size_t i)
{
	t_list	*cur;
	t_list	*prev;

	if (*lst == NULL)
		return ;
	cur = *lst;
	prev = NULL;
	while (cur != NULL && i--)
	{
		prev = cur;
		cur = cur->next;
	}
	if (cur == NULL)
		return ;
	if (prev == NULL)
		*lst = cur->next;
	else
		prev->next = cur->next;
	(*del)(cur->content, cur->content_size);
	free(cur);
}
