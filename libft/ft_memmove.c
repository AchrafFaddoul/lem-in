/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 15:29:48 by afaddoul          #+#    #+#             */
/*   Updated: 2018/10/10 21:51:01 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*source;

	dest = (char*)dst;
	source = (char*)src;
	if (dest > source)
	{
		while (len--)
			dest[len] = source[len];
	}
	else
		ft_memcpy(dest, source, len);
	return ((void*)dest);
}
