/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrepalce.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 21:00:44 by ybahlaou          #+#    #+#             */
/*   Updated: 2019/04/15 00:34:06 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_strnewlen(const char *str, const char *old,
						size_t old_len, size_t new_len)
{
	char	*ptr;
	size_t	len;
	size_t	step;

	if (old_len == 0 || old_len == new_len)
		return (ft_strlen(str));
	len = 0;
	while (*str)
	{
		if ((ptr = ft_strstr(str, old)) == NULL)
		{
			len += ft_strlen(str);
			break ;
		}
		step = (size_t)(ptr - str);
		len += new_len + step;
		str += old_len + step;
	}
	return (len);
}

char		*ft_strreplace(const char *str, const char *old, const char *new)
{
	char	*res;
	char	*ptr;
	size_t	i;
	size_t	lens[3];

	if ((lens[0] = ft_strlen(old)) == 0)
		return (ft_strdup(str));
	lens[1] = ft_strlen(new);
	if ((res = ft_strnew(ft_strnewlen(str, old, lens[0], lens[1]))) == NULL)
		return (NULL);
	i = 0;
	while (*str)
	{
		if ((ptr = ft_strstr(str, old)) == NULL)
		{
			ft_strcpy(res + i, str);
			break ;
		}
		lens[2] = (size_t)(ptr - str);
		ft_strncpy(res + i, str, lens[2]);
		ft_strcpy(res + i + lens[2], new);
		i += lens[1] + lens[2];
		str += lens[0] + lens[2];
	}
	return (res);
}
