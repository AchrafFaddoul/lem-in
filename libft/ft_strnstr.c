/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 09:24:54 by ybahlaou          #+#    #+#             */
/*   Updated: 2018/10/29 15:30:48 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*to_find)
		return ((char*)str);
	i = 0;
	while (*str && i < len)
	{
		j = 0;
		while (*(str + j) && *(to_find + j) &&
				i + j < len && *(to_find + j) == *(str + j))
			j++;
		if (!*(to_find + j))
			return ((char*)str);
		i++;
		str++;
	}
	return (NULL);
}
