/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strctrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:10:44 by ybahlaou          #+#    #+#             */
/*   Updated: 2018/12/25 18:30:26 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strctrim(const char *s, char c)
{
	size_t	len;

	while (*s && *s == c)
		s++;
	len = ft_strlen(s);
	if (len == 0)
		return (ft_strdup(""));
	len--;
	while (*(s + len) == c)
		len--;
	return (ft_strsub(s, 0, len + 1));
}
