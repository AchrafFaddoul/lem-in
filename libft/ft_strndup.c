/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 02:30:04 by ybahlaou          #+#    #+#             */
/*   Updated: 2019/04/18 03:53:13 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t n)
{
	char	*str;
	size_t	i;

	i = ft_strlen(src);
	if (n >= i)
		return (ft_strdup(src));
	str = (char*)malloc(sizeof(char) * (n + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (n--)
	{
		*(str + i) = *(src + i);
		i++;
	}
	*(str + i) = '\0';
	return (str);
}
