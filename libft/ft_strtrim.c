/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 15:12:42 by afaddoul          #+#    #+#             */
/*   Updated: 2018/10/21 18:10:32 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	start;
	unsigned int	i;
	size_t			length;
	size_t			len;
	char			*ptr;

	if (!(s))
		return (0);
	i = 0;
	start = 0;
	len = 0;
	length = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
		return (ft_strdup(""));
	start = i;
	while (s[length] == ' ' || s[length] == '\n' || s[length] == '\t')
		length--;
	len = length - (size_t)i + 1;
	ptr = ft_strsub(s, start, len);
	return (ptr);
}
