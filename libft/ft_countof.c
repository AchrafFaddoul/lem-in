/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countof.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 08:50:38 by afaddoul          #+#    #+#             */
/*   Updated: 2019/10/02 10:01:51 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t 		ft_countof(const char *str, int c)
{
	size_t	counter;

	counter  = 0;
	while(*str)
	{
		if (*str == c)
			counter++;
		str++;
	}
	return (counter);
}
