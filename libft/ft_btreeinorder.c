/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreeapplyinorder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 16:36:16 by ybahlaou          #+#    #+#             */
/*   Updated: 2019/04/27 00:16:06 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btreeinorder(t_btree *root, void (*ft)(t_btree*))
{
	if (root == NULL)
		return ;
	ft_btreeinorder(root->left, ft);
	(*ft)(root);
	ft_btreeinorder(root->right, ft);
}
