/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:29:08 by qrosa             #+#    #+#             */
/*   Updated: 2017/05/16 01:34:02 by yoko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

bool	read_file(t_env **env)
{
	char	*current_line;
	char	state;

	state = STATE_INIT;
	while (get_next_line(0, &current_line) && (state >= 0))  // EXIT GNL if (bad_line or EOF or empty_line)
		state = check_line(state, current_line, env);
	if (state < 0)
		return (exit_error(state, current_line, env));
	ft_putendl("\nEND_CHECK_MORAY");		// DEBUG
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
	debug_struct(env);		//DEBUG
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
