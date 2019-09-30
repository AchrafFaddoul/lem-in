/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:09:53 by afaddoul          #+#    #+#             */
/*   Updated: 2019/09/30 14:14:40 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				ft_isnumber(char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[0] == '+')
			i++;
		if (!(ft_isdigit(str[i++])))
			return (0);
	}
	return (1);
}

int				ft_isoverflow(char *str)
{
	static char	ll_max[19] = "9223372036854775807";
	int			i;
	int			len;

	i = 0;
	len = ft_strlen(str);
	if (len > 19)
		return (0);
	else if (len < 19)
		return (1);
	else
	{
		while (str[i])
		{
			if (ll_max[i] < str[i])
				return (0);
			i++;
		}
	}
	return (1);
}

int 			get_ants(t_farm *farm, char *line)
{
	if (!(ft_isnumber(line)))
		return (0);
	if (!(ft_isoverflow(line)))
		return (0);
	farm->ants = ft_atol(line);
	return (1);
}
