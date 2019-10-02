/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreedel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 13:59:27 by ybahlaou          #+#    #+#             */
/*   Updated: 2019/05/02 14:04:18 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_btreedel(t_btree **root, void (*del)(void*, size_t))
{
	if (root != NULL && *root != NULL)
	{
		ft_btreedel(&(*root)->left, del);
		ft_memdel((void**)&(*root)->left);
		ft_btreedel(&(*root)->right, del);
		ft_memdel((void**)&(*root)->right);
		(*del)((*root)->content, (*root)->content_size);
		ft_memdel((void**)root);
	}
}
