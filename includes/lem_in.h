/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smouzdah <smouzdah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 11:42:47 by afaddoul          #+#    #+#             */
/*   Updated: 2019/12/23 17:57:18 by smouzdah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# define GET_ENTRY(index) ((t_room*)(farm->rooms_ht->entries[index]->content))

typedef struct			s_room
{
	char			*key;
	int	 		index;
	int 			flow;
	t_dlist			*edges;
}				t_room;

typedef struct 			s_item
{
	int 			index;
	int				prev;
}				t_item;

typedef struct 			s_simulation
{
	int 				node_nb;
	int 				ants_nb;
	int 				path_size;
}						t_simulation;

typedef struct 			s_node
{
	int 				ants;
	char 				*room;
}						t_node;

typedef struct			s_group
{
	t_dlist				**path;
	long long 			score;
	int  				node_nb;
	int 				path_nb;
}						t_group;


typedef struct			s_farm
{
	long long		ants;
	size_t			paths_nb;
	t_group			grps[2];
	t_dlist			*rooms;
	t_room			*start;
	t_room			*end;
	t_hashtable		*rooms_ht;
}				t_farm;

t_farm				*ft_farmfill(t_farm *farm, t_dlist *lst);
int				ft_getants(t_farm *farm, char *line);
t_dlist				*read_input(void);
int				ft_parsedata(t_farm *farm);
void				ft_error(void);
t_farm				*ft_farmnew(void);
int				get_ants(t_farm *farm, char *line);
int				ft_isnumber(char *str);
int				ft_isoverflow(char *str);
t_element			*ft_getrooms(t_farm *farm, t_dlist *lst);
t_room				*ft_roomnew(const char *name);
t_room				*ft_roomparse(const char *input);
t_hashtable			*ft_dlisttoht(t_farm *farm);
int				ft_edgesparse(const char *input,
			char **vertex, char **neighbor);
t_farm				*ft_getedges(t_farm *farm, t_element *lst);
int				ft_edgesparse(const char *input,
			char **vertex, char **neighbor);
void				ft_enqueue(t_dlist *lst, t_element *elm);
int				ft_dequeue(t_dlist *lst);
t_item				*ft_itemnew(int value, int prev);
int				ft_search_item(t_dlist *lst, int target);
int				ft_bfs(t_farm *farm, int i_grp);
int				ft_search_item(t_dlist *lst, int target);
int				ft_ismatched(t_room *room, t_dlist *standby, t_dlist *lst_vis);
void			ft_flowmark(t_room *room, int value);
void			ft_hashmapupdate(t_farm *farm, t_dlist *path);
int				ft_pathextract(t_farm *farm, t_dlist *lst_vis, t_dlist *standby, int i_grp, int dequeued);
int             ft_bfsmanager(t_farm *farm);
int				ft_putinstructions(t_farm *farm);

#endif
