/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 10:56:48 by ybahlaou          #+#    #+#             */
/*   Updated: 2019/04/28 00:49:02 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	sub = ft_strnew(len);
	if (sub != NULL)
	{
		i = 0;
		while (i < len)
		{
			*(sub + i) = *(s + start);
			start++;
			i++;
		}
		*(sub + i) = '\0';
	}
	return (sub);
}
