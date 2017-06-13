/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:29:08 by qrosa             #+#    #+#             */
/*   Updated: 2017/06/13 03:15:49 by yoko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "../includes/lem_in.h"

bool	read_file(t_env **env)
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
//	printf("State == %d\n", state); // DEBUG
	if (state < STATE_CHECK_LINK)
		return (exit_error(state, current_line, env));
	ft_free_line(&current_line);
	return (SUCCESS);
}

bool	start_lem_in(void)
{
	t_env	*env;

	env = init_struct();
	if (read_file(&env) == SUCCESS)
	{
		resolve(env);
		delete_matrice_graph(&(env->graph));
	}
//	debug_struct(env);		//DEBUG // maybe implement option for one bonus.
	free_struct(&env);
	return (SUCCESS);
}

int		main(int argc, char **argv)
{
	if (argc == 1 && argv)
		return (start_lem_in());
	else
		return (output_help(ERROR));
}
