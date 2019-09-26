/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 12:36:41 by afaddoul          #+#    #+#             */
/*   Updated: 2018/10/11 13:04:12 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*string_1;
	const unsigned char	*string_2;
	size_t				i;

	i = 0;
	string_1 = (const unsigned char*)s1;
	string_2 = (const unsigned char*)s2;
	while (i < n)
	{
		if (string_1[i] != string_2[i])
			return (string_1[i] - string_2[i]);
		i++;
	}
	return (0);
}
