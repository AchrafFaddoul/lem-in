#include "lem_in.h"

t_simulation		**ft_simdestroy(t_farm *farm, t_simulation **sim_arr)
{
	size_t 			i;
	size_t 			size;

	i = 0;
	size = farm->grps[0].path_nb;
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
			return (ft_simdestroy(farm, sim_arr));
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
	printf("sim_arr created\n");
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

int	 				ft_putinstructions(t_farm *farm)
{
	t_simulation 	**sim_arr;

	sim_arr = ft_simulation(farm);
	if (!sim_arr)
		return (0);
	return (1);
	//	ft_pathnew(farm. sim_arr);
}
