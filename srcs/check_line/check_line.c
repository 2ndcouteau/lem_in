/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoko <yoko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 01:33:49 by yoko              #+#    #+#             */
/*   Updated: 2017/06/09 18:01:12 by yoko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	check_line(char state, char *current_line, t_env **env)
{
	(*env)->nb_line++;
	if (current_line == NULL)
		return (ERR_NOTHING);
	if (ft_is_empty_line(current_line))
		return (check_status_empty_line(state));
	if (state == STATE_CHECK_ANT)
		return (check_nb_ant(current_line, env));
	else if (state == STATE_CHECK_ROOM)
	{
		if ((state = check_room(current_line, env)) <= STATE_CHECK_ROOM)
			return (state);
	}
	if (state == STATE_CHECK_FIRST_LINK)
	{
		if ((state = check_room_step_valid(env)) != STATE_CHECK_LINK)
			return (state);
	}
	if (state == STATE_CHECK_LINK)
		state = check_links(current_line, env);
	return (state);
}
