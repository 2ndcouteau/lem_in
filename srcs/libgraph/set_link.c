/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 06:58:00 by qrosa             #+#    #+#             */
/*   Updated: 2017/06/27 12:03:54 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libmatgraph.h"

char	set_link(t_matrice_graph *graph, unsigned int src, unsigned int dst,
																char oriented)
{
	if (dst < graph->size && src < graph->size)
	{
		graph->matrix[src][dst] = 1;
		if (!oriented)
			set_link(graph, dst, src, 1);
		return (1);
	}
	return (-1);
}
