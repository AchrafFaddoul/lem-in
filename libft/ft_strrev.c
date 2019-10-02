/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 23:39:28 by ybahlaou          #+#    #+#             */
/*   Updated: 2019/06/05 23:45:39 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_swp(char *a, char *b)
{
	char	z;

	z = *a;
	*a = *b;
	*b = z;
}

char		*ft_strrev(char *str)
{
	size_t	len;
	size_t	mid;
	size_t	i;

	len = ft_strlen(str);
	mid = len / 2;
	i = 0;
	while (i < mid)
	{
		ft_swp(str + i, str + len - i - 1);
		i++;
	}
	return (str);
}
