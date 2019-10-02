/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreefind.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 18:58:37 by ybahlaou          #+#    #+#             */
/*   Updated: 2019/05/01 19:19:10 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_btreefind(t_btree *root, void *to_find, int (*cmp)(void*, void*))
{
	t_btree		*elm;

	if (root == NULL)
		return (NULL);
	else if (cmp(root->content, to_find) == 0)
		return (root);
	else if ((elm = ft_btreefind(root->left, to_find, cmp)) != NULL)
		return (elm);
	else
		return (ft_btreefind(root->right, to_find, cmp));
}
