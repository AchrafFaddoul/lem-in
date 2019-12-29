/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resprinter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 20:37:44 by afaddoul          #+#    #+#             */
/*   Updated: 2019/12/29 20:38:47 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
	int				i;
	int				j;
	int				cnt;

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

void				ft_resultprinter(long long ants, char *room)
{
	ft_putchar('L');
	ft_putnbr(ants);
	ft_putchar('-');
	ft_putstr(room);
}

void				ft_instruprinter(t_farm *farm, t_node **paths)
{
	int				i;
	int				j;
	int				cnt;
	int				instr;

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
				if (instr < (cnt - 1))
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
	t_element		*current;
	t_element		*to_del;

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
