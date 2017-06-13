#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../includes/libft.h"
#include "../includes/lem_in.h"

static void				delete_path_array(t_path ***paths)
{
	unsigned long	i;

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

static int				get_path_len(void *ref)
{
	t_path 			*path;

	path = (t_path*)ref;
	return ((int)path->len);
}

int						resolve(t_env *env)
{
	t_path			**paths;
	unsigned long	turns;
	unsigned long	pathslen;

	paths = get_optimum_paths(env->graph, env->start_room, env->end_room,
							  env->nb_ant);
	if (paths)
	{
		pathslen = ft_arraylen((void**)paths) - 1;
		ft_quicksort((void**)paths, 0, pathslen, get_path_len);
		turns = compute_turns(paths, env->nb_ant);
		ft_putnendl(env->save_map, env->pos_map);
		print_solution(paths, env, turns);
	}
	else
		return (ERROR);
	delete_path_array(&paths);
	return (SUCCESS);
}
