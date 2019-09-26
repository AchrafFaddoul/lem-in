/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 21:44:34 by afaddoul          #+#    #+#             */
/*   Updated: 2019/07/05 18:14:33 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(unsigned long long n)
{
	char	*ptr;
	int		i;

	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (!(ptr = ft_strnew(ft_nb_len(n))))
		return (0);
	ptr[i++] = (n % 10) + 48;
	while ((n /= 10) != 0)
		ptr[i++] = (n % 10) + 48;
	ptr[i] = '\0';
	return (ft_strrev(ptr));
}
