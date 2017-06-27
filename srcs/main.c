/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:29:08 by qrosa             #+#    #+#             */
/*   Updated: 2017/06/27 15:40:39 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <fcntl.h>
#include <unistd.h>

bool		read_file(t_env **env)
{
	char	*current_line;
	char	state;

	state = STATE_CHECK_ANT;
	current_line = NULL;
	while ((state >= 0) && get_next_line(0, &current_line))
	{
		state = check_line(state, current_line, env);
		ft_free_line(&current_line);
	}
	if ((*env)->tab_coor != NULL)
		(*env)->tab_coor = free_hashtab(env, 1);
	if (state < STATE_CHECK_LINK)
		return (exit_error(state, current_line, env));
	ft_free_line(&current_line);
	return (SUCCESS);
}

static void	check_fd(void)
{
	if (fcntl(STDIN_FILENO, F_GETFD) == -1)
	{
		ft_putendl_fd("STDIN_FILENO is not available.", 2);
		exit(ERROR);
	}
}

bool		start_lem_in(void)
{
	t_env	*env;

	check_fd();
	env = init_struct();
	if (read_file(&env) == SUCCESS)
	{
		resolve(env);
		delete_matrice_graph(&(env->graph));
	}
	free_struct(&env);
	return (SUCCESS);
}

int			main(int argc, char **argv)
{
	if (argc == 1 && argv)
		return (start_lem_in());
	else
		return (output_help(ERROR));
}
