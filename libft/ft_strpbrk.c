/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 13:49:09 by ybahlaou          #+#    #+#             */
/*   Updated: 2019/05/12 17:51:59 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpbrk(const char *str, const char *charset)
{
	const char	*cur;
	char		*ptr;

	while (*str)
	{
		cur = charset;
		while (*cur)
		{
			if ((ptr = ft_strchr(str, *cur)) != NULL)
				return ((char*)ptr);
			cur++;
		}
		str++;
	}
	return (NULL);
}
