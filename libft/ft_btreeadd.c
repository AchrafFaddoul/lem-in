/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreeadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:04:06 by ybahlaou          #+#    #+#             */
/*   Updated: 2019/10/02 10:16:18 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btreeadd(t_btree **root, t_btree *elm,
		int (*cmp)(t_btree *elm, t_btree *side))
{
	if (*root == NULL)
		*root = elm;
	else
	{
		if ((*cmp)(elm, *root) < 0)
			ft_btreeadd(&(*root)->left, elm, cmp);
		else
			ft_btreeadd(&(*root)->right, elm, cmp);
	}
}
