/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smouzdah <smouzdah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 11:42:47 by afaddoul          #+#    #+#             */
/*   Updated: 2020/01/12 18:53:56 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <stdlib.h>

# define GET_ENTRY(index) ((t_room*)(farm->rooms_ht->entries[index]->content))

# define MAX_INT		2147483647
# define MAX_FLOW		0
# define UPDATED		1
# define ERROR			-2
# define T_INVALID		0
# define T_COMMENT		1
# define T_LINKS		2
# define T_INSTRUCTION	0
# define T_START		1
# define T_END			2
# define T_CMT			3
# define T_VERTEX		4

typedef struct			s_room
{
	char				*key;
	int					index;
	int					flow;
	t_dlist				*edges;
}						t_room;

typedef struct			s_item
{
	int					index;
	int					prev;
}						t_item;

typedef struct			s_simulation
{
	int					node_nb;
	int					ants_nb;
	int					path_size;
}						t_simulation;

typedef struct			s_node
{
	long long			ants;
	char				*room;
}						t_node;

typedef struct			s_group
{
	t_dlist				**path;
	long long			score;
	int					node_nb;
	int					path_nb;
}						t_group;

typedef struct			s_farm
{
	long long			ants;
	size_t				paths_nb;
	t_group				grps[2];
	t_dlist				*rooms;
	t_room				*start;
	t_room				*end;
	t_hashtable			*rooms_ht;
	t_dlist				*input;
}						t_farm;

t_farm					*ft_farmfill(t_farm *farm, t_dlist *lst);
int						ft_getants(t_farm *farm, char *line);
t_dlist					*read_input(void);
int						ft_parsedata(t_farm *farm);
void					ft_error(void);
t_farm					*ft_farmnew(void);
int						get_ants(t_farm *farm, char *line);
int						ft_isnumber(char *str);
int						ft_isoverflow(char *str);
t_element				*ft_getrooms(t_farm *farm, t_element *elm);
t_room					*ft_roomnew(char *name);
t_room					*ft_roomparse(const char *input);
t_hashtable				*ft_dlisttoht(t_farm *farm);
int						ft_edgesparse(const char *input,
				char **vertex, char **neighbor);
t_farm					*ft_getedges(t_farm *farm, t_element *lst);
int						ft_edgesparse(const char *input,
				char **vertex, char **neighbor);
void					ft_enqueue(t_dlist *lst, t_element *elm);
int						ft_dequeue(t_dlist *lst);
t_item					*ft_itemnew(int value, int prev);
void					ft_flowmark(t_room *room, int value);
void					ft_revflowmark(t_room *room, int value);
void					ft_hashmapupdate(t_farm *farm, t_dlist *path);
int						ft_maxflow_manager(t_farm *farm);
int						ft_maxflow(t_farm *farm, int i_grp);
int						ft_flowextract(t_farm *farm, t_dlist *vis,
				int dequeued, int i_grp);
int						ft_putinstructions(t_farm *farm);
void					ft_roomdel(t_room **room);
int						ft_pathdel(t_dlist **path);
void					ft_grpdestroy(t_dlist **paths, int path_nb);
void					ft_farmdel(t_farm *farm);
void					item_del(void *content);
t_room					*ft_roomdup(t_room *room);
t_simulation			**ft_simdestroy(t_simulation **sim_arr, size_t size);
t_simulation			**ft_simnew(t_farm *farm);
t_simulation			**ft_simulation(t_farm *farm);
void					del(void *content);
int						ft_minlen(t_farm *farm, t_simulation **sim_arr);
void					ft_resultprinter(long long ants, char *room);
void					ft_structfiller(t_farm *farm, t_node **paths);
void					ft_antsmover(t_farm *farm, t_node **paths,
				int *i, int *done_ants);
size_t					ft_paths_nb(size_t size, t_simulation **sim_arr);
t_node					**ft_pathsnew(t_farm *farm, t_simulation **sim_arr);
int						ft_antsmove(t_node *path, t_simulation *sim_arr,
				int *ants);
void					ft_resultprinter(long long ants, char *room);
void					ft_instruprinter(t_farm *farm, t_node **paths);
void					ft_inputprinter(t_farm *farm);
void					ft_antsmover(t_farm *farm, t_node **paths,
				int *i, int *done_ants);
void					ft_structfiller(t_farm *farm, t_node **paths);
t_node					**ft_pathsdestroy(t_node **paths, size_t size);
t_element				*ft_antsparser(t_farm *farm, t_dlist *lst);
int						ft_verif_item(t_dlist *lst, int target);

#endif
