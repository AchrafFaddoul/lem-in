/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_edgeparse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 16:10:46 by afaddoul          #+#    #+#             */
/*   Updated: 2019/10/07 08:42:11 by afaddoul         ###   ########.fr       */
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
		ft_memdel((void**)links);
		return (NULL);
	}
	input += len + 1;
	if(!(links[1] = ft_strdup(input)))
	{
		ft_memdel((void**)links);
		return (NULL);
	}
	return (links);
}

int			ft_edgesparse(const char *input, char **vertex, char **neighbor)
{
	char 	**links;

	if (!(links = extract_links(input)))
		return (0);
	*vertex = *links;
	*neighbor = *(links + 1);
	free(links);
	return (1);
}
