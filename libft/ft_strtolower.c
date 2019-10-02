/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:44:10 by ybahlaou          #+#    #+#             */
/*   Updated: 2019/04/17 19:44:26 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_call(char c)
{
	return ((char)ft_tolower((char)c));
}

char		*ft_strtolower(const char *str)
{
	return (ft_strmap(str, &ft_call));
}
