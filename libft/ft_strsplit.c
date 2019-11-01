/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 19:37:05 by afaddoul          #+#    #+#             */
/*   Updated: 2018/10/23 12:27:29 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_strplit(char const *s, char c)
{
	char	**ptr;
	int		i[2];
	int		k;

	i[0] = 0;
	k = 0;
	if (!(ptr = (char**)malloc(sizeof(char*) * (ft_word_counter(s, c) + 1))))
		return (NULL);
	while (s[i[0]] != '\0')
	{
		while (s[i[0]] == c && s[i[0]])
			i[0]++;
		i[1] = i[0];
		while (s[i[1]] && s[i[1]] != c)
			i[1]++;
		if (s[i[0]] && i[1] > i[0])
		{
			ptr[k++] = ft_strsub(s, i[0], i[1] - i[0]);
			i[0] = i[1];
		}
		else
			break ;
	}
	ptr[k] = 0;
	return (ptr);
}

char		**ft_strsplit(char const *s, char c)
{
	if (s == NULL)
		return (NULL);
	else
		return (ft_strplit(s, c));
}
