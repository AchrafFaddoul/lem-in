/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 16:28:51 by ybahlaou          #+#    #+#             */
/*   Updated: 2019/04/25 22:12:37 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_elminelm(t_list *a, t_list *b)
{
	a->content = b->content;
	a->content_size = b->content_size;
	return (b->next);
}

static t_list	*ft_ncpy(t_list *lst, size_t n)
{
	t_list	*cpy;
	t_list	*cur;

	if (lst == NULL || n == 0)
		return (NULL);
	cpy = ft_lstnew(lst->content, lst->content_size);
	cur = cpy;
	lst = lst->next;
	while (lst != NULL && n-- >= 2)
	{
		cur->next = ft_lstnew(lst->content, lst->content_size);
		cur = cur->next;
		lst = lst->next;
	}
	return (cpy);
}

static void		ft_merge(t_list *orig,
		t_list *a, t_list *b, int (*cmp)(t_list*, t_list*))
{
	while (a != NULL && b != NULL)
	{
		if (cmp(a, b) > 0)
			b = ft_elminelm(orig, b);
		else
			a = ft_elminelm(orig, a);
		orig = orig->next;
	}
	while (a != NULL)
	{
		a = ft_elminelm(orig, a);
		orig = orig->next;
	}
	while (b != NULL)
	{
		b = ft_elminelm(orig, b);
		orig = orig->next;
	}
}

static void		ft_mergesort(t_list *lst,
		size_t size, int (*cmp)(t_list*, t_list*))
{
	size_t	mid;
	t_list	*left;
	t_list	*right;

	if (size <= 1)
		return ;
	mid = size / 2;
	left = ft_ncpy(lst, mid);
	right = ft_ncpy(ft_lstget(lst, mid), size - mid);
	ft_mergesort(left, mid, cmp);
	ft_mergesort(right, size - mid, cmp);
	ft_merge(lst, left, right, cmp);
	while (left != NULL)
	{
		lst = left;
		left = left->next;
		free(lst);
	}
	while (right != NULL)
	{
		lst = right;
		right = right->next;
		free(lst);
	}
}

void			ft_lstsort(t_list *lst, int (*cmp)(t_list*, t_list*))
{
	ft_mergesort(lst, ft_lstsize(lst), cmp);
}
