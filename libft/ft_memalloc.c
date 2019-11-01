/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 19:00:49 by afaddoul          #+#    #+#             */
/*   Updated: 2018/10/16 19:40:36 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*buff;

	buff = (void*)malloc(size);
	if (buff == NULL)
		return (NULL);
	ft_bzero(buff, size);
	return (buff);
}
