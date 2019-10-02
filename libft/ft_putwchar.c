/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 20:11:18 by ybahlaou          #+#    #+#             */
/*   Updated: 2018/11/09 15:34:06 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putwchar(wchar_t c)
{
	if (c >= 0x0 && c <= 0x7F)
		ft_putchar(c);
	else if (c <= 0x7FF)
	{
		ft_putchar((c >> 0x6) | 0xC0);
		ft_putchar((c & 0x3F) | 0x80);
	}
	else if (c <= 0xFFFF)
	{
		ft_putchar((c >> 0xC) | 0xE0);
		ft_putchar(((c >> 0x6) & 0x3F) | 0x80);
		ft_putchar((c & 0x3F) | 0x80);
	}
	else if (c <= 0x10FFFF)
	{
		ft_putchar((c >> 0x12) | 0xF0);
		ft_putchar(((c >> 0xC) & 0x3F) | 0x80);
		ft_putchar(((c >> 0x6) & 0x3F) | 0x80);
		ft_putchar((c & 0x3F) | 0x80);
	}
}
