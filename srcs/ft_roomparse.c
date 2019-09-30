/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roomparse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 18:52:53 by afaddoul          #+#    #+#             */
/*   Updated: 2019/09/30 19:54:30 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
// room1 1 2
int	ft_isnumber(const char *str, char c)
{
	size_t	len;

	len = 0;
	while (1)
	{
		if (*str == c)
			break ;
		if (!ft_isdigit(*str))
			return (0);
		len++;
		str++;
	}
	return (len);
}

static char	*extract_name(const char *input)
{
	size_t	len;
	char	*name;

	if (!(len = ft_strclen(input, ' ')))
		return (NULL);
	if (*(input + len) == '\0')
		return (NULL);
	if (*(input + len + 1) == ' ')
		return (NULL);
	name = ft_strndup(input, len);
	input += len + 1;
	if (!(len = ft_isnumber(input, ' ')))
	{
		ft_strdel(&name);
		return (NULL);
	}
	if (!ft_isnumber(input, '\0'))
		ft_strdel(&name);
	return (name);
}

t_room		*ft_roomparse(const char *input)
{
	(void)input;
	return (NULL);
}
