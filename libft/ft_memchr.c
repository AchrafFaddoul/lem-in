/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 18:49:36 by ybahlaou          #+#    #+#             */
/*   Updated: 2018/11/09 15:32:59 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *ptr_s;

	ptr_s = (unsigned char*)s;
	while (n >= 1)
	{
		if (*ptr_s == (unsigned char)c)
			return ((void*)ptr_s);
		n--;
		ptr_s++;
	}
	return (NULL);
}
