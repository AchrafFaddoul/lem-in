/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 20:43:02 by ybahlaou          #+#    #+#             */
/*   Updated: 2019/10/02 10:16:17 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned int	nb;
	unsigned int	max;
	int				sign;

	max = 1 << (sizeof(int) * 8 - 1);
	while (ft_isspace(*str))
		str++;
	sign = *str == '-' ? -1 : 1;
	str += *str == '-' || *str == '+';
	nb = 0;
	while (ft_isdigit(*str))
	{
		nb = 10 * nb + *str - '0';
		if ((nb > max && sign == -1) || (sign == 1 && nb >= max))
			return (-1);
		str++;
	}
	return (nb * sign);
}
