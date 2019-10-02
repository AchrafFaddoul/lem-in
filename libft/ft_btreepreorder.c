/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreeapplypreorder.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 16:31:12 by ybahlaou          #+#    #+#             */
/*   Updated: 2019/04/27 00:15:35 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btreepreorder(t_btree *root, void (*ft)(t_btree*))
{
	if (root == NULL)
		return ;
	(*ft)(root);
	ft_btreepreorder(root->left, ft);
	ft_btreepreorder(root->right, ft);
}
