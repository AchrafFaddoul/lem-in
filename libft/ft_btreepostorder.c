/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreeapplypostorder.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 16:37:31 by ybahlaou          #+#    #+#             */
/*   Updated: 2019/04/27 00:14:49 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btreepostorder(t_btree *root, void (*ft)(t_btree*))
{
	if (root == NULL)
		return ;
	ft_btreepostorder(root->left, ft);
	ft_btreepostorder(root->right, ft);
	(*ft)(root);
}
