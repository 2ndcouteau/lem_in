/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:29:08 by qrosa             #+#    #+#             */
/*   Updated: 2017/05/11 17:51:24 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

bool	start_lem_in(void)
{
	char *current_line;

	while (get_next_line(0, &current_line))  // EXIT GNL if (bad_line or EOF or empty_line)
	{
		ft_putendl(current_line); // DEBUG
	}

	// Prepare:
	// 1) Array with all rooms (index+name)   cf: HASH table --> {Name + index(matrix line)}
	// 2) Matricial array with char[N_rooms] // A voir --> Ou mettre ?= (poid du noeud())
	ft_putendl("current_line");
	return (SUCCESS);
}

int		main(int argc, char **argv)
{
	if (argc == 1 && argv)
		return (start_lem_in());
		// call program
	else
		return (output_help(ERROR));
}


// Le nombre de fourmis que l'on peut envoyer "simultanement" dans les salles corresponds au mieux/au maximum , au nombre de lien sur le noeud de sortie (END Node)

// Si un noeud (intermediaire (ni START, ni END)) a plusieurs liens en AMONT, alors il faut considerer un seul et unique chemin via ce noeud.
// Les autres "chemins" potentiel devront etre simplement ignorer. Bien sur, il faut estimer le chemin le plus court via ce noeud.
