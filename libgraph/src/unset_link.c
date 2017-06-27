/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 06:58:00 by avallete          #+#    #+#             */
/*   Updated: 2017/06/27 12:04:27 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libmatgraph.h"

char	unset_link(t_matrice_graph *graph, unsigned int src,
												unsigned int dst, char oriented)
{
	if (dst < graph->size && src < graph->size)
	{
		graph->matrix[src][dst] = 0;
		if (!oriented)
			unset_link(graph, dst, src, 1);
		return (1);
	}
	return (-1);
}
