/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 15:47:10 by qrosa             #+#    #+#             */
/*   Updated: 2017/06/27 15:48:49 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	push_to_paths(t_anthill *anthill, t_path **paths)
{
	unsigned long	i;

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
