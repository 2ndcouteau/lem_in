/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 19:45:00 by avallete          #+#    #+#             */
/*   Updated: 2017/06/11 19:45:00 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/lem_in.h"

static void	init_ants(t_ant *ants, unsigned long lemins)
{
	unsigned long i;

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
	unsigned long i;

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
	unsigned long i;

	i = 0;

	while (i < (lemins + 1))
	{
		if (ants[i].path)
			ants[i].path_position += 1;
		++i;
	}
}

static void	push_to_paths(t_anthill *anthill, t_path **paths)
{
	unsigned long i;

	i = 1;
	if (anthill->waiting_ants > 0)
	{
		anthill->ants[anthill->waiting_ants].path = paths[0];
		anthill->waiting_ants--;
		while (paths[i] && anthill->waiting_ants)
		{
			anthill->ants[anthill->waiting_ants].path = paths[i];
			anthill->waiting_ants--;
			++i;
		}
	}
}

static void	print_ants(t_ant *ants, unsigned long lemins)
{
	unsigned long i;

	i = 0;
	while (i < (lemins + 1))
	{
		if (ants[i].path)
		{
			ft_putchar('L');
			ft_putnbr((int)i);
			ft_putchar('-');
			ft_putnbr((int)(int)ants[i].path->path[(int)ants[i].path_position]);
			ft_putchar(' ');
		}
		++i;
	}
	ft_putchar('\n');
}

void	print_solution(t_path **paths, unsigned long lemins,
					   unsigned long turns)
{
	t_anthill anthill;

	anthill.waiting_ants = lemins;
	if ((anthill.ants = (t_ant*)malloc(sizeof(t_ant) * (lemins + 1))))
	{
		init_ants(anthill.ants, lemins);
		while (turns)
		{
			move_forward(anthill.ants, lemins);
			eject_out_ants(anthill.ants, lemins);
			push_to_paths(&anthill, paths);
			print_ants(anthill.ants, lemins);
			--turns;
		}
		free(anthill.ants);
	}
	else
		ft_putstr("ERROR\n");
}