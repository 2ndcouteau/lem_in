/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_optimum_paths.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 01:23:00 by avallete          #+#    #+#             */
/*   Updated: 2017/06/27 10:14:25 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	max_path_len(unsigned long lemins, unsigned long shortest_len)
{
	if (shortest_len > 1)
		return (ft_abs(((shortest_len - 1) - lemins)) + shortest_len);
	return (1);
}

t_path		**get_optimum_paths(t_matrice_graph *graph, unsigned long src,
										unsigned long dst, unsigned long lemins)
{
	t_path			**paths;
	t_pathfind		*pfind;
	t_path			*shortest_path;
	t_matrice_graph *path_graph;

	paths = NULL;
	pfind = new_pathfind(src, dst, graph->size, graph->size);
	if (pfind)
	{
		if ((shortest_path = dijkstra(graph, pfind)))
		{
			pfind->max_dist = max_path_len(lemins, shortest_path->len);
			path_graph = bhandari(graph, shortest_path, pfind, lemins);
			paths = graph_to_paths(path_graph, pfind);
			delete_matrice_graph(&path_graph);
			delete_path(&shortest_path);
		}
	}
	delete_pathfind(&pfind);
	return (paths);
}
