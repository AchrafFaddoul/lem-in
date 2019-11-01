/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 11:25:34 by afaddoul          #+#    #+#             */
/*   Updated: 2018/10/21 14:00:02 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		x;
	int		y;
	char	echangeur;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	x = i - 1;
	y = 0;
	while (x > y)
	{
		echangeur = str[x];
		str[x] = str[y];
		str[y] = echangeur;
		y++;
		x--;
	}
	return (str);
}
