/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 21:09:01 by afaddoul          #+#    #+#             */
/*   Updated: 2018/10/23 12:40:34 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		position;

	i = 0;
	j = 0;
	if (!(haystack || needle))
		return (NULL);
	if (needle[j] == '\0' || haystack == needle)
		return ((char*)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		position = i;
		while (needle[j] != '\0' && (haystack[position] == needle[j]))
		{
			j++;
			position++;
		}
		if (needle[j] == '\0' && (i + j) <= len)
			return ((char*)haystack + i);
		i++;
	}
	return (NULL);
}
