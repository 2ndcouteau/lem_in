/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 19:45:00 by qrosa             #+#    #+#             */
/*   Updated: 2017/06/27 15:47:20 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/lem_in.h"

static void	init_ants(t_ant *ants, unsigned long lemins)
{
	unsigned long	i;

	i = 0;
	while (i < (lemins + 1))
	{
		ants[i].path = NULL;
		ants[i].path_position = 1;
		++i;
	}
}

static void	eject_out_ants(t_ant *ants, unsigned long lemins)
{
	unsigned long	i;

	i = 0;
	while (i < (lemins + 1))
	{
		if (ants[i].path && ants[i].path_position > ants[i].path->len)
			ants[i].path = NULL;
		++i;
	}
}

static void	move_forward(t_ant *ants, unsigned long lemins)
{
	unsigned long	i;

	i = 0;
	while (i < (lemins + 1))
	{
		if (ants[i].path)
			ants[i].path_position += 1;
		++i;
	}
}

void		print_solution(t_path **paths, t_env *env, unsigned long turns)
{
	t_anthill		anthill;
	unsigned long	lemins;

	lemins = env->nb_ant;
	anthill.waiting_ants = lemins;
	if ((anthill.ants = (t_ant*)malloc(sizeof(t_ant) * (lemins + 1))))
	{
		init_ants(anthill.ants, lemins);
		if (paths[0]->len > 1)
		{
			while (turns)
			{
				move_forward(anthill.ants, lemins);
				eject_out_ants(anthill.ants, lemins);
				push_to_paths(&anthill, paths);
				print_ants(anthill.ants, lemins, env);
				--turns;
			}
		}
		else
			print_direct_way(paths, &anthill, lemins, env);
		free(anthill.ants);
	}
	else
		ft_putendl("ERROR : Malloc answer structure failed");
}
