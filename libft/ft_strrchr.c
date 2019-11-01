/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 15:59:36 by afaddoul          #+#    #+#             */
/*   Updated: 2018/10/15 16:29:23 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	cast;
	int		len;

	len = ft_strlen((char*)s);
	cast = (char)c;
	while (len >= 0)
	{
		if (s[len] == cast)
			return ((char*)s + len);
		len--;
	}
	return (NULL);
}
