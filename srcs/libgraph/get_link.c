/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 06:52:00 by qrosa             #+#    #+#             */
/*   Updated: 2017/06/27 11:53:04 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libmatgraph.h"

char	get_link(t_matrice_graph *graph, unsigned int src, unsigned int dst)
{
	if (src < graph->size && dst < graph->size)
		return (graph->matrix[src][dst]);
	return (0);
}
