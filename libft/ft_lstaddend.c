/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 15:43:06 by ybahlaou          #+#    #+#             */
/*   Updated: 2018/11/01 11:25:08 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **lst, t_list *elm)
{
	t_list	*cur;

	if (*lst == NULL)
		*lst = elm;
	else
	{
		cur = *lst;
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = elm;
	}
}
