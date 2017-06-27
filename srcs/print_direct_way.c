/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_direct_way.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 10:23:30 by qrosa             #+#    #+#             */
/*   Updated: 2017/06/27 10:23:46 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	print_direct_way(t_path **paths, t_anthill *anthill,
											unsigned long lemins, t_env *env)
{
	while (anthill->waiting_ants)
		push_to_paths(anthill, paths);
	print_ants(anthill->ants, lemins, env);
}
