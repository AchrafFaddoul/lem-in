/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_edgeparse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 16:10:46 by afaddoul          #+#    #+#             */
/*   Updated: 2019/10/04 17:18:55 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static char **extract_links(const char *input)
{
	size_t	len;
	char  	**links;

	if (!(len = ft_strclen(input, '-')))
		return (NULL);
	if (*(input + len) == '\0')
		return (NULL);
	if (*(input + len + 1) == '-')
		return (NULL);
	if (!(links = (char**)ft_memalloc(sizeof(char*) * 2)))
		return (NULL);
	if (!(links[0] = ft_strndup(input, len)))
	{
		ft_memdel(&links);
		return (NULL);
	}
	input += len + 1;
	while (*input)
		len++;
	if(!(links[1] = ft_strndup(input, len)))
	{
		ft_memdel(((void**)&links[0]));
		ft_memdel((void**)links);
		return (NULL);
	}
	return (links);
}

t_edges		*ft_edgesparse(const char *input)
{
	t_edges *edge;
	char 	**links;

	if (!(links = extract_links(input)))
		return (NULL);
	if (!(edge = ft_edgenew(links)))
	{
		ft_memdel((void**)(&links[0]));
		ft_memdel((void**)(&links[1]));
		return (NULL);
	}
	return (edge);
}
