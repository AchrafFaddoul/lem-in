/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_nb_len.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 18:08:01 by afaddoul          #+#    #+#             */
/*   Updated: 2019/07/06 12:49:53 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_unsigned_nb_len(unsigned long long n)
{
	unsigned long long	number;
	int					counter;

	counter = 0;
	if (n <= 0)
	{
		counter++;
		number = n * -1;
	}
	else
		number = n;
	while (number > 0)
	{
		number /= 10;
		++counter;
	}
	return (counter);
}
