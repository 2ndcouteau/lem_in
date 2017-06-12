/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_room_step_valid.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoko <yoko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 00:59:36 by yoko              #+#    #+#             */
/*   Updated: 2017/06/09 01:23:23 by yoko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "../../includes/lem_in.h"

char	check_room_step_valid(t_env **env)
{
	if ((*env)->nb_room == 0)
		return (ERR_NO_ROOM);
	else if ((*env)->nb_room == 1)
		return (ERR_MORE_ROOM);
	else if ((*env)->start_room < 0)
		return (ERR_SET_START);
	else if ((*env)->end_room < 0)
		return (ERR_SET_END);
	(*env)->graph = new_matrice_graph((*env)->nb_room);
	return (STATE_CHECK_LINK);
}
