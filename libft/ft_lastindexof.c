/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lastindexof.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:52:31 by ybahlaou          #+#    #+#             */
/*   Updated: 2019/04/14 23:09:04 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_lastindexof(const char *str, char c)
{
	size_t	i;
	size_t	index;

	i = 0;
	index = -1;
	while (*str)
	{
		if (*str == c)
			index = i;
		str++;
		i++;
	}
	return (index);
}
