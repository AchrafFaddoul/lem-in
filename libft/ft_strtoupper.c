/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:39:37 by ybahlaou          #+#    #+#             */
/*   Updated: 2019/04/17 19:43:46 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_call(char c)
{
	return ((char)ft_toupper((char)c));
}

char		*ft_strtoupper(const char *str)
{
	return (ft_strmap(str, &ft_call));
}
