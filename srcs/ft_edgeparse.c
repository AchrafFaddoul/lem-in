/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_edgeparse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 16:10:46 by afaddoul          #+#    #+#             */
/*   Updated: 2019/12/29 16:45:20 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


static int	ft_isroom(int c)
{
         if ((c >= 33 && c <= 44) || (c >=46 && c <=126))
                 return (1);
         return (0);
}

static 	char 	**extract_links(const char *input)
{
	int 	i;
	char 	**links;

	i = 0;
	while (input[i] && input[i] != '-')
		i++;
	if (!input[i])
		return (NULL);
	if (!(links = (char**)ft_memalloc(sizeof(char*) * 2)))
		return (NULL);
	if (!(links[0] = ft_strndup(input, i))
		|| (links[0][0] == 'L' || links[0][0] == '#'))
	{
		ft_memdel((void**)links);
		return (NULL);
	}
	input += i + 1;
	i = -1;
	while (links[0][++i])
	{
		if (!ft_isroom(links[0][i]))
		{
			ft_strdel((char**)&links[0]);
			ft_memdel((void**)links);
			return (NULL);
		}
	}
	if (!(links[1] = ft_strdup(input))
		|| (links[1][0] == 'L' || links[1][0] == '#'))
	{
		ft_strdel((char**)&links[0]);
		ft_memdel((void**)links);
		return (NULL);
	}
	i = -1;
	while (links[1][++i])
	{
		if (!ft_isroom(links[1][i]))
		{
			ft_strdel((char**)&links[0]);
			ft_strdel((char**)&links[1]);
			ft_memdel((void**)links);
			return (NULL);
		}
	}
	return (links);
}


int				ft_edgesparse(const char *input,
		char **vertex, char **neighbor)
{
	char		**links;

	if (!(links = extract_links(input)))
		return (0);
	*vertex = *links;
	*neighbor = *(links + 1);
	free(links);
	return (1);
}
