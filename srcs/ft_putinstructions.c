/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putinstructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 18:32:33 by afaddoul          #+#    #+#             */
/*   Updated: 2019/12/22 19:58:13 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putinstructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 23:13:45 by afaddoul          #+#    #+#             */
/*   Updated: 2019/12/22 18:31:49 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_simulation		**ft_simdestroy(t_simulation **sim_arr, size_t size)
{
	size_t 			i;

	i = 0;
	while (i < size)
	{
		free(sim_arr[i]);
		i++;
	}
	free(sim_arr);
	return (NULL);
}

t_simulation		**ft_simnew(t_farm *farm)
{
	t_simulation 	**sim_arr;
	size_t			size;
	size_t 			i;

	i = 0;
	size = farm->grps[0].path_nb;
	sim_arr = (t_simulation**)ft_memalloc(sizeof(t_simulation*) * size);
	if (!sim_arr)
		return (NULL);
	while (i < size)
	{
		sim_arr[i] = (t_simulation*)ft_memalloc(sizeof(t_simulation*));
		if (!sim_arr[i])
			return (ft_simdestroy(sim_arr, size));
		i++;
	}
	return (sim_arr);
}

static void			ft_structinit(t_farm *farm, t_simulation **sim_arr)
{
	size_t			i;
	size_t 			size;

	i = 0;
	size = (size_t)farm->grps[0].path_nb;
	while (i < size)
	{
		sim_arr[i]->node_nb = farm->grps[0].path[i]->size;
		i++;
	}
}

static int			ft_minlen(t_farm *farm, t_simulation **sim_arr)
{
	size_t			size;
	int 			min_len;
	int 			target;
	size_t 			i;

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

t_simulation 		**ft_simulation(t_farm *farm)
{
	t_simulation 	**sim_arr;
	t_dlist			**path;
	size_t 			i;
	long long		ants_nb;

	i = 0;
	ants_nb = farm->ants;
	sim_arr = ft_simnew(farm);
	if (!sim_arr)
		return (sim_arr);
	path = farm->grps[0].path;
	ft_structinit(farm, sim_arr);
	while (ants_nb)
	{
		i = ft_minlen(farm, sim_arr);
		sim_arr[i]->node_nb++;
		sim_arr[i]->ants_nb++;
		ants_nb--;
	}
	i = -1;
	while ((int)(++i) < farm->grps[0].path_nb)
	{
		printf("%d\n", sim_arr[i]->ants_nb);
	}
	return (sim_arr);
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
	int 			j;

	j = 1;
	tmp = farm->grps[0].path[i]->tail;
	while (tmp)
	{
		path[i][j].room = (GET_ENTRY((((t_item*)(tmp->content)))->index))->key;
		tmp = tmp->prev;
		j++;
	}
}

t_node 				**ft_pathsnew(t_farm *farm, t_simulation **sim_arr)
{
	size_t			size;
	size_t 			i;
	t_node 			**paths;

	i = 0;
	size = farm->grps[0].path_nb;
	while (i < (size_t)farm->grps[0].path_nb)
	{
		if (sim_arr[i][0].ants_nb == 0)
			break ;
		i++;
	}
	farm->paths_nb = i;
	size = i;
	i = 0;
	paths = (t_node**)ft_memalloc(sizeof(t_node*) * size);
	if (!paths)
		return (NULL);
	while (i < size)
	{
		paths[i] = (t_node*)ft_memalloc(sizeof(t_node) * (farm->grps[0].path[i]->size + 1));
		if (!paths[i])
			return (ft_pathsdestroy(paths, farm->paths_nb));
		paths[i][0].ants = sim_arr[i]->ants_nb;
		ft_pathfiller(farm, paths, i);
		i++;
	}
	return (paths);
}

int 				ft_antsmove(t_node *path, t_simulation *sim_arr, int *ants)
{
	int 			end_reached;
	int 			i;

	i = sim_arr->path_size - 1;
	end_reached = 0;
	while (i >= 0 && path[0].ants)
	{
		if (i == 0)
		{
			printf("|%d| * |%d| \n",path[i].ants, *ants);
			path[i].ants--;
			path[1].ants = (*ants)++;
		}
		else
		{
			if ((i + 1) == (sim_arr->path_size - 1))
				end_reached++;
			if (!path[i].ants)
			{
				path[i+1].ants = path[i].ants;
				path[i].ants = 0;
			}
		}
		i--;
	}
	return (end_reached);
}

void 				ft_instruprinter(t_farm *farm, t_node **paths,
		t_simulation **sim_arr)
{
	int 			i;
	int 			j;
	int				prev_printed;

	prev_printed = 0;
	i = 0;
	sim_arr = NULL;
	while (i < (int)farm->paths_nb)
	{
		j = ((int)farm->grps[0].path[i]->size);
		while (j > 0)
		{
			if (paths[i][j].ants != 0)
			{
				//prev_printed = 1;
				printf("L%d-%s", paths[i][j].ants, paths[i][j].room);
				if ((i != (int)farm->paths_nb - 1 || (j != 1 &&  paths[i][j - 1].ants != 0)))
				{
					printf(" ");
				}
			}
			j--;
		}
		i++;
	}
	printf("\n");
}

void				ft_resultprinter(t_farm *farm, t_simulation **sim_arr,
		t_node **paths)
{
	long long		counter;
	int 			ants;
	size_t 			i;

	counter = farm->ants;
	ants = 1;
	i = 0;
	while (counter)
	{
		counter -= ft_antsmove(paths[i], sim_arr[i], &ants);
		i++;
	}
	ft_instruprinter(farm, paths, sim_arr);
}

int	 				ft_putinstructions(t_farm *farm)
{
	t_simulation 	**sim_arr;
	t_node 			**paths;

	printf("*********************\n");
	sim_arr = ft_simulation(farm);
	if (!sim_arr)
		return (0);
	if (!(paths = ft_pathsnew(farm, sim_arr)))
		return (0);

	int i = 0;
	size_t j;
	while (i < (int)farm->paths_nb)
	{
		j = 0;
		while (j < farm->grps[0].path[i]->size + 1)
		{
			printf("|%d:", paths[i][j].ants);
			printf("%s|", paths[i][j].room);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("***************************\n\n");
	int i2 = 0;
	int j2;
	int done_ants = 0;
	int ants = 1;
	while (done_ants < farm->ants)
	{
		j2 = farm->grps[0].path[i2]->size;
		while (j2 >= 0)
		{
		//	printf("ants in room = %d | j %d | i = %d\n",paths[i2][j2].ants,j2, i2);
			if (paths[i2][j2].ants != 0)
			{
				if (j2 == 0)
				{
				//	printf("dkhelt i = %d\n", i2);
					paths[i2][j2 + 1].ants = ants++;
					paths[i2][j2].ants--;
				}
				else if (j2 == (int)farm->grps[0].path[i2]->size){
					done_ants++;
					paths[i2][j2].ants = 0;
				}
				else 
				{
					paths[i2][j2 + 1].ants = paths[i2][j2].ants;
					paths[i2][j2].ants = 0;
				}
			}
			j2--;
		}
		i2++;
	//	printf("i = %d | paths nb = %d\n", i2,(int)farm->paths_nb );
		if (i2 >= (int)farm->paths_nb)
		{
			i2 = 0;
			ft_instruprinter(farm, paths, sim_arr);
		/*	i = 0;
			while (i < (int)farm->paths_nb)
			{
				j = 0;
				while (j < farm->grps[0].path[i]->size + 1)
				{
					printf("|%d:", paths[i][j].ants);
					printf("%s|", paths[i][j].room);
					j++;
				}
				printf("\n");
				i++;
			}*/
		}





	}


	//	ft_resultprinter(farm, sim_arr, paths);
	return (1);
}
