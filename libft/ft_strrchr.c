/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 10:52:20 by ybahlaou          #+#    #+#             */
/*   Updated: 2018/10/29 15:30:28 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = 0;
	while (*(s + len))
		len++;
	while (len > 0)
	{
		if (*(s + len) == (char)c)
			return ((char*)(s + len));
		len--;
	}
	if (*(s + len) == (char)c)
		return ((char*)(s + len));
	return (NULL);
}
