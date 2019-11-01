/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 10:46:23 by afaddoul          #+#    #+#             */
/*   Updated: 2019/08/15 19:15:31 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			*dest;
	const unsigned char		*source;
	size_t					i;
	unsigned char			cast;

	i = 0;
	dest = (unsigned char*)dst;
	source = (const unsigned char*)src;
	cast = (unsigned char)c;
	while (i < n)
	{
		dest[i] = source[i];
		if (source[i] == cast)
			return ((void*)dest + i + 1);
		i++;
	}
	return (NULL);
}
