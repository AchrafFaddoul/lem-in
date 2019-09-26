/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 14:35:41 by afaddoul          #+#    #+#             */
/*   Updated: 2018/10/15 15:58:12 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	cast;
	int		i;

	i = 0;
	cast = (char)c;
	while (s[i] != '\0' || cast == '\0')
	{
		if (s[i] == cast)
			return ((char*)s + i);
		i++;
	}
	return (NULL);
}
