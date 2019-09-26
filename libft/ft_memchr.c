/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 10:05:19 by afaddoul          #+#    #+#             */
/*   Updated: 2018/10/11 11:05:55 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*string;
	unsigned char			cast;
	size_t					i;

	i = 0;
	string = (const unsigned char*)s;
	cast = (unsigned char)c;
	while (i < n)
	{
		if (string[i] == cast)
			return ((void*)(string + i));
		i++;
	}
	return (NULL);
}
