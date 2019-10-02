/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strendswith.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 20:34:09 by ybahlaou          #+#    #+#             */
/*   Updated: 2018/10/29 13:31:22 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strendswith(const char *str, const char *sub)
{
	size_t	str_len;
	size_t	sub_len;

	str_len = ft_strlen(str);
	sub_len = ft_strlen(sub);
	if (str_len < sub_len)
		return (0);
	return (ft_strequ(str + str_len - sub_len, sub));
}
