/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isulong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 21:56:25 by afaddoul          #+#    #+#             */
/*   Updated: 2019/12/29 21:56:26 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isulong(const char *str, char c)
{
	int			size;
	const char	*max;

	max = "18446744073709551615";
	size = 0;
	while (1)
	{
		if (*(str + size) == c)
			break ;
		if (!ft_isdigit(*(str + size)))
			return (0);
		size++;
	}
	if (size > 20)
		return (0);
	if (size < 20)
		return (size);
	if (ft_strncmp(str, max, size) > 0)
		return (0);
	return (size);
}
