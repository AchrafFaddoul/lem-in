/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 19:34:43 by ybahlaou          #+#    #+#             */
/*   Updated: 2018/11/15 19:34:44 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wcsdup(const wchar_t *src)
{
	wchar_t	*str;
	wchar_t	*head;

	str = (wchar_t*)malloc(sizeof(wchar_t) * (ft_wcslen(src) + 1));
	if (str == NULL)
		return (NULL);
	head = str;
	while (*src)
		*str++ = *src++;
	*str = 0;
	return (head);
}
