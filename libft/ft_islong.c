/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islong.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 10:27:00 by ybahlaou          #+#    #+#             */
/*   Updated: 2019/10/02 11:05:18 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_islong(const char *str, char c)
{
	int			size;
	const char	*max;

	max = "9223372036854775807";
	str += *str == '+' || *str == '-';
	size = 0;
	while (1)
	{
		if (*(str + size) == c)
			break ;
		if (!ft_isdigit(*(str + size)))
			return (0);
		size++;
	}
	if (size > 19)
		return (0);
	if (size < 19)
		return (size);
	if (ft_strncmp(str, max, size) > 0)
		return (0);
	return (size);
}
