/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elemnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 22:02:23 by afaddoul          #+#    #+#             */
/*   Updated: 2019/12/29 22:02:24 by afaddoul         ###   ########.fr       */
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
