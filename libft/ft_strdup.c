/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 17:14:42 by afaddoul          #+#    #+#             */
/*   Updated: 2019/06/25 09:22:13 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*pointer;

	i = 0;
	len = ft_strlen(s1);
	pointer = (char*)malloc(sizeof(char) * (len + 1));
	if (pointer == NULL)
		return (NULL);
	while (i < len)
	{
		pointer[i] = s1[i];
		i++;
	}
	pointer[i] = '\0';
	return (pointer);
}
