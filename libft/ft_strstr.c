/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 18:43:06 by afaddoul          #+#    #+#             */
/*   Updated: 2019/06/26 15:43:37 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	int		position;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		j = 0;
		position = i;
		while (needle[j] != '\0' && haystack[position] == needle[j])
		{
			position++;
			j++;
		}
		if (needle[j] == '\0')
			return ((char*)(haystack + i));
		i++;
	}
	return (NULL);
}
