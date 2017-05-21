/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:29:08 by qrosa             #+#    #+#             */
/*   Updated: 2017/05/21 16:59:01 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

bool	read_file(t_env **env)
{
	char	*current_line;
	char	state;

	state = STATE_CHECK_ANT;
	current_line = NULL;
	while ((state >= 0) && get_next_line(0, &current_line))
		state = check_line(state, current_line, env);
	if (state < STATE_CHECK_LINK)		 // Need to change it to STATE_CHECK_END after implementation of CHECK_LINKS
		return (exit_error(state, current_line, env));
	ft_putendl("\nEND_CHECK_MORAY");		// DEBUG
	current_line = ft_free_line(&current_line);
	return (SUCCESS);
}
	// Prepare:
	// 1) Array with all rooms (index+name)   cf: HASH table --> {Name + index(matrix line)}
	// 2) Matricial array with char[N_rooms] // A voir --> Ou mettre ?= (poid du noeud())


bool	start_lem_in(void)
{
	t_env	*env;

	env = init_struct();
	read_file(&env);
	ft_putnendl(env->save_map, env->pos_map);
	debug_struct(env);		//DEBUG // maybe implement option for one bonus.
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


// Le nombre de fourmis que l'on peut envoyer "simultanement" dans les salles corresponds au mieux/au maximum , au nombre de lien sur le noeud de sortie (END Node)

// Si un noeud (intermediaire (ni START, ni END)) a plusieurs liens en AMONT, alors il faut considerer un seul et unique chemin via ce noeud.
// Les autres "chemins" potentiel devront etre simplement ignorer. Bien sur, il faut estimer le chemin le plus court via ce noeud.
