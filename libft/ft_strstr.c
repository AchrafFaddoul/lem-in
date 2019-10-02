/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 09:24:54 by ybahlaou          #+#    #+#             */
/*   Updated: 2018/10/05 11:29:33 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	size_t	i;

	if (!*to_find)
		return ((char*)str);
	while (*str)
	{
		i = 0;
		while (*(to_find + i) && *(to_find + i) == *(str + i))
			i++;
		if (!*(to_find + i))
			return ((char*)str);
		str++;
	}
	return (NULL);
}
