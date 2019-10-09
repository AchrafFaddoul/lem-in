/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roomparse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 18:52:53 by afaddoul          #+#    #+#             */
/*   Updated: 2019/10/04 21:37:05 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	is_coord(const char *str, char c)
{
	size_t	len;

	len = 0;
	while (1)
	{
		if (*str == '+' || *str == '-')
			str++;
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
	if (!(name = ft_strndup(input, len)))
		return (NULL);
	input += len + 1;
	if (!(len = is_coord(input, ' ')))
	{
		ft_strdel(&name);
		return (NULL);
	}
	input += len + 1;
	if (!(is_coord(input, '\0')))
		ft_strdel(&name);
	return (name);
}

t_room		*ft_roomparse(const char *input)
{
	t_room	*room;
	char 	*name;

	if (!(name = extract_name(input)))
		return (NULL);
	if (!(room = ft_roomnew(name)))
		ft_memdel((void**)&room);
	ft_strdel(&name);
	return (room);
}
