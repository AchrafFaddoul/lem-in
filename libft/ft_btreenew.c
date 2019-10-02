/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreenew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 14:36:09 by ybahlaou          #+#    #+#             */
/*   Updated: 2019/04/25 15:05:00 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_btreenew(const void *content, size_t content_size)
{
	t_btree	*new;

	if ((new = (t_btree*)malloc(sizeof(t_btree))) != NULL)
	{
		new->left = NULL;
		new->right = NULL;
		new->content = (void*)content;
		if (content == NULL)
			new->content_size = 0;
		else
			new->content_size = content_size;
	}
	return (new);
}
