/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 16:30:30 by ybahlaou          #+#    #+#             */
/*   Updated: 2019/04/15 00:08:01 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_p;
	unsigned char	*src_p;

	dst_p = (unsigned char*)dst;
	src_p = (unsigned char*)src;
	if (src_p > dst_p)
		ft_memcpy(dst, src, len);
	else
	{
		while (len-- > 0)
			*(dst_p + len) = *(src_p + len);
	}
	return (dst);
}
