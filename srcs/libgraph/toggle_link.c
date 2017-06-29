/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toggle_link.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 08:59:00 by qrosa             #+#    #+#             */
/*   Updated: 2017/06/27 12:04:13 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libmatgraph.h"

char	toggle_link(t_matrice_graph *graph, unsigned int src,
												unsigned int dst, char oriented)
{
	if (dst < graph->size && src < graph->size)
	{
		if (graph->matrix[src][dst])
			graph->matrix[src][dst] = 0;
		else
			graph->matrix[src][dst] = 1;
		if (!oriented)
			toggle_link(graph, dst, src, 1);
		return (1);
	}
	return (-1);
}
