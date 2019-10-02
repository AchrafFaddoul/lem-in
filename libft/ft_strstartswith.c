/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstartswith.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 20:33:04 by ybahlaou          #+#    #+#             */
/*   Updated: 2018/10/10 22:22:24 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strstartswith(const char *str, const char *sub)
{
	size_t	sub_len;

	sub_len = ft_strlen(sub);
	if (sub_len == 0)
		return (1);
	return (ft_strncmp(str, sub, sub_len) == 0);
}
