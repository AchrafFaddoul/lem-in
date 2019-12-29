/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putinstructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 23:13:45 by afaddoul          #+#    #+#             */
/*   Updated: 2019/12/29 19:24:40 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int					ft_minlen(t_farm *farm, t_simulation **sim_arr)
{
	size_t			size;
	int				min_len;
	int				target;
	size_t			i;

	i = 0;
	min_len = 2147483647;
	target = 2147483647;
	size = (size_t)farm->grps[0].path_nb;
	while (i < size)
	{
		if (sim_arr[i]->node_nb < min_len)
		{
			target = i;
			min_len = sim_arr[i]->node_nb;
		}
		i++;
	}
	return (target);
}

static t_node		**ft_pathsdestroy(t_node **paths, size_t size)
{
	size_t			i;

	i = 0;
	while (i < size)
	{
		free(paths[i]);
		i++;
	}
	free(paths);
	return (NULL);
}

static void			ft_pathfiller(t_farm *farm, t_node **path, size_t i)
{
	t_element		*tmp;
	int				j;

	j = 1;
	tmp = farm->grps[0].path[i]->tail;
	while (tmp)
	{
		path[i][j].room = (GET_ENTRY((((t_item*)(tmp->content)))->index))->key;
		tmp = tmp->prev;
		j++;
	}
}

size_t				ft_paths_nb(size_t size, t_simulation **sim_arr)
{
	size_t			i;

	i = 0;
	while (i < size)
	{
		if (sim_arr[i][0].ants_nb == 0)
			break ;
		i++;
	}
	return (i);
}

t_node				**ft_pathsnew(t_farm *farm, t_simulation **sim_arr)
{
	size_t			size;
	size_t 			i;
	t_node 			**paths;

	i = ft_paths_nb(farm->grps[0].path_nb, sim_arr);
	farm->paths_nb = i;
	size = i;
	i = 0;
	paths = (t_node**)ft_memalloc(sizeof(t_node*) * size);
	if (!paths)
		return (NULL);
	while (i < size)
	{
		paths[i] = (t_node*)ft_memalloc(sizeof(t_node) *
				(farm->grps[0].path[i]->size + 1));
		if (!paths[i])
			return (ft_pathsdestroy(paths, farm->paths_nb));
		paths[i][0].ants = sim_arr[i]->ants_nb;
		ft_pathfiller(farm, paths, i);
		i++;
	}
	return (paths);
}

int					ft_antsmove(t_node *path, t_simulation *sim_arr, int *ants)
{
	int				end_reached;
	int				i;

	i = sim_arr->path_size - 1;
	end_reached = 0;
	while (i >= 0 && path[0].ants)
	{
		if (i == 0)
		{
			path[i].ants--;
			path[1].ants = (*ants)++;
		}
		else
		{
			if ((i + 1) == (sim_arr->path_size - 1))
				end_reached++;
			if (!path[i].ants)
			{
				path[i + 1].ants = path[i].ants;
				path[i].ants = 0;
			}
		}
		i--;
	}
	return (end_reached);
}

static int			ft_instrucounter(t_farm *farm, t_node **paths)
{
	int 			i;
	int 			j;
	int 			cnt;

	i = 0;
	cnt = 0;
	while (i < (int)farm->paths_nb)
	{
		j = ((int)farm->grps[0].path[i]->size);
		while (j > 0)
		{
			if (paths[i][j].ants != 0)
				cnt++;
			j--;
		}
		i++;
	}
	return (cnt);
}

void 				ft_resultprinter(long long ants, char *room)
{
	ft_putchar('L');
	ft_putnbr(ants);
	ft_putchar('-');
	ft_putstr(room);
}

void				ft_instruprinter(t_farm *farm, t_node **paths)
{
	int 			i;
	int 			j;
	int 			cnt;
	int 			instr;

	if (!(cnt = ft_instrucounter(farm, paths)))
		return ;
	i = -1;
	instr = 0;
	while (++i < (int)farm->paths_nb)
	{
		j = ((int)farm->grps[0].path[i]->size);
		while (j > 0)
		{
			if (paths[i][j].ants != 0)
			{
				ft_resultprinter(paths[i][j].ants, paths[i][j].room);
				if (instr < cnt-1)
					ft_putchar(' ');
				instr++;
			}
			j--;
		}
	}
	ft_putchar('\n');
}

void				ft_inputprinter(t_farm *farm)
{
	t_element 		*current;
	t_element 		*to_del;

	current = farm->input->head;
	while (current)
	{
		to_del = current;
		current = current->next;
		ft_putstr((char*)(((t_element*)(to_del))->content));
		ft_putchar('\n');
		if (!current)
			ft_putchar('\n');
		del(to_del->content);
		ft_memdel((void**)&to_del);
	}
	ft_memdel((void**)&farm->input);
}

void				ft_structfiller(t_farm *farm, t_node **paths)
{
	int i;
	int j;
	int done_ants;
	int ants;

	ants = 1;
	done_ants = 0;
	i = 0;
	while (done_ants < farm->ants)
	{
		j = farm->grps[0].path[i]->size;
		while (j >= 0)
		{
			if (paths[i][j].ants != 0)
			{
				if (j == 0)
				{
					paths[i][j + 1].ants = ants++;
					paths[i][j].ants--;
				}
				else if (j == (int)farm->grps[0].path[i]->size)
				{
					done_ants++;
					paths[i][j].ants = 0;
				}
				else
				{
					paths[i][j + 1].ants = paths[i][j].ants;
					paths[i][j].ants = 0;
				}
			}
			j--;
		}
		i++;
		if (i >= (int)farm->paths_nb)
		{
			ft_instruprinter(farm, paths);
			i = 0;
		}
	}
}

int	 				ft_putinstructions(t_farm *farm)
{
	t_simulation 	**sim_arr;
	t_node 			**paths;

	sim_arr = ft_simulation(farm);
	if (!sim_arr)
		return (0);
	if (!(paths = ft_pathsnew(farm, sim_arr)))
		return (0);
	ft_inputprinter(farm);
	ft_structfiller(farm, paths);
	ft_pathsdestroy(paths, ft_paths_nb(farm->grps[0].path_nb, sim_arr));
	ft_simdestroy(sim_arr, farm->grps[0].path_nb);
	return (1);
}
