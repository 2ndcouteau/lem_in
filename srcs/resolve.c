#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../includes/libft.h"
#include "../includes/lem_in.h"

static int	max_path_len(unsigned long lemins, unsigned long shortest_len)
{
	return (ft_abs(((shortest_len - 1) - lemins)) + shortest_len);
}

static t_path **get_optimum_paths(t_matrice_graph *graph, unsigned long src,
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

static void	delete_path_array(t_path ***paths)
{
	unsigned long i;

	if (*paths)
	{
		i = 0;
		while ((*paths)[i])
		{
			delete_path(&((*paths)[i]));
			++i;
		}
		free(*paths);
		*paths = NULL;
	}
}

static unsigned long	compute_turns(t_path **paths, unsigned long lemins)
{
	unsigned long	turns;
	unsigned long	max_path_len;
	unsigned long	i;

	i = ft_arraylen((void**)paths);
	max_path_len = (paths[i - 1])->len;
	turns = (((lemins / (i)) + (max_path_len - 1)));
	return (turns);
}

static int		get_path_len(void *ref)
{
	t_path *path;

	path = (t_path*)ref;
	return ((int)path->len);
}

int resolve(t_matrice_graph *graph, unsigned long lemins) {
	t_path			**paths;
	unsigned long	turns;
	unsigned long	pathslen;

	paths = get_optimum_paths(graph, 1001, 1002, lemins);
	if (paths)
	{
		pathslen = ft_arraylen((void**)paths) - 1;
		ft_quicksort((void**)paths, 0, pathslen, get_path_len);
		turns = compute_turns(paths, lemins);
		print_solution(paths, lemins, turns);
	}
	else
		return (ERROR);
	delete_path_array(&paths);
	return (SUCCESS);
}
