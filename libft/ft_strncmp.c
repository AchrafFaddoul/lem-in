/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 12:19:12 by afaddoul          #+#    #+#             */
/*   Updated: 2018/10/16 12:30:55 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (s1[i] && s2[j] && s1[i] == s2[j] && n)
	{
		i++;
		j++;
		n--;
	}
	if (n == 0)
		return (0);
	else if (s1[i] != s2[j])
		return ((unsigned char)s1[i] - (unsigned char)s2[j]);
	return (0);
}
