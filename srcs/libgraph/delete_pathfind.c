/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_pathfind.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 18:40:00 by qrosa             #+#    #+#             */
/*   Updated: 2017/06/27 11:49:15 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libmatgraph.h"

void	delete_pathfind(t_pathfind **pathfind)
{
	if (*pathfind)
	{
		if ((*pathfind)->parent)
			free((*pathfind)->parent);
		if ((*pathfind)->dist)
			free((*pathfind)->dist);
		if ((*pathfind)->visited)
			free((*pathfind)->visited);
		free(*pathfind);
		*pathfind = NULL;
	}
}
