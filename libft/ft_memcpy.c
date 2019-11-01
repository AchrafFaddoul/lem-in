/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 13:28:30 by afaddoul          #+#    #+#             */
/*   Updated: 2018/10/23 19:58:16 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dest;
	const char	*source;

	dest = (char*)dst;
	source = (const char*)src;
	i = 0;
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return ((void*)dest);
}
