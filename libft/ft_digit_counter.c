/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit_counter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 13:56:42 by afaddoul          #+#    #+#             */
/*   Updated: 2019/07/05 18:08:17 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nb_len(long long n)
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
