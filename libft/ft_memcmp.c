/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 19:03:34 by ybahlaou          #+#    #+#             */
/*   Updated: 2018/10/29 16:44:25 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr_s1;
	unsigned char	*ptr_s2;

	ptr_s1 = (unsigned char*)s1;
	ptr_s2 = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (*(ptr_s1 + i) != *(ptr_s2 + i))
			return (*(ptr_s1 + i) - *(ptr_s2 + i));
		i++;
	}
	return (0);
}
