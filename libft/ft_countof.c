/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countof.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 08:50:38 by afaddoul          #+#    #+#             */
/*   Updated: 2019/10/02 08:54:06 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int 		ft_countof(const char *str, int c)
{
	int 	counter;

	counter  = 0;
	while(*str)
	{
		if (*str == c)
			counter++;
		str++;
	}
	return (counter);
}
