/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 10:36:20 by ybahlaou          #+#    #+#             */
/*   Updated: 2018/10/29 16:45:25 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*newstr;
	size_t	newstr_len;
	size_t	i;

	newstr_len = ft_strlen(s);
	newstr = ft_strnew(newstr_len);
	if (newstr != NULL)
	{
		i = 0;
		while (*(s + i))
		{
			*(newstr + i) = (*f)(*(s + i));
			i++;
		}
		*(newstr + i) = '\0';
	}
	return (newstr);
}
