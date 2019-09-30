/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 11:42:47 by afaddoul          #+#    #+#             */
/*   Updated: 2019/09/30 18:30:53 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <stdlib.h>

ttypedef struct			s_room
{
	char				*room;
	long long 			hash_code;
	t_element			*start;
	t_element			*end;
}						t_room;

typedef struct			s_edges
{
	char				*vertex;
	char 				*neighbor;
}						t_edges;

typedef struct			s_farm
{
	long long			ants;
	t_dlist				*rooms;
	t_dlist				*edges;
	// t_hashmap			*rooms_map;
	// t_hashmap			*edges_map;
}						t_farm;

t_farm					*ft_fillfarm(t_farm *farm, t_dlist *lst);
int						get_ants(t_farm *farm, char *line);
t_dlist					*read_input(void);
int						ft_parsedata(t_farm *farm);
void					ft_error(void);
t_farm					*ft_farmnew(void);
int						get_ants(t_farm *farm, char *line);
int						ft_isnumber(char *str);
int						ft_isoverflow(char *str);
t_dlist					*ft_getrooms(t_farm *farm, ft_dlist *lst);

#endif
