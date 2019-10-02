/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 14:31:43 by ybahlaou          #+#    #+#             */
/*   Updated: 2019/01/26 00:35:34 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*elm;

	elm = (t_list*)malloc(sizeof(t_list));
	if (elm != NULL)
	{
		elm->content_size = content_size;
		elm->content = (void*)content;
		if (content == NULL)
			elm->content_size = 0;
		elm->next = NULL;
	}
	return (elm);
}
