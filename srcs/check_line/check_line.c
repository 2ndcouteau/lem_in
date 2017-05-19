/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoko <yoko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 01:33:49 by yoko              #+#    #+#             */
/*   Updated: 2017/05/20 00:27:09 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	check_line(char state, char *current_line, t_env **env)
{
	if (current_line == NULL)
		return (ERR_NOTHING);
//	ft_putendl(current_line); // DEBUG
	if (ft_is_empty_line(current_line))
		return (check_status_empty_line(state));
	if (state == STATE_CHECK_ANT)
		return (check_nb_ant(current_line, env));
	else if (state == STATE_CHECK_ROOM)
	{
		if ((state = check_room(current_line, env)) <= STATE_CHECK_ROOM)
			return (state);
	}
	if (state == STATE_CHECK_LINK)
	{
		if ((*env)->nb_room == 0)
			return (ERR_NO_ROOM);
		else if ((*env)->nb_room == 1)
			return (ERR_MORE_ROOM);
		else if ((*env)->start_room == NULL)
			return (ERR_SET_START);
		else if ((*env)->end_room == NULL)
			return (ERR_SET_END);
		if (buff_add_str(env, current_line))
			return (ERR_MAP_SCALE);
//		ft_putendl("check_links");
	}
	return (state);
}
