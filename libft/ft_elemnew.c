/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elemnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 16:12:23 by afaddoul          #+#    #+#             */
/*   Updated: 2019/10/01 19:31:24 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_element	*ft_elemnew(const void *content)
{
	t_element	*elm;

	elm = (t_element*)ft_memalloc(sizeof(t_element));
	if (!elm)
		return (NULL);
	elm->content = (void*)content;
	return (elm);
}
