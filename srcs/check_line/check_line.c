/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoko <yoko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 01:33:49 by yoko              #+#    #+#             */
/*   Updated: 2017/06/09 01:23:31 by yoko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	check_line(char state, char *current_line, t_env **env)
{
	(*env)->nb_line++;
	if (current_line == NULL)
		return (ERR_NOTHING);
//	ft_putendl(current_line); // DEBUG
	if (ft_is_empty_line(current_line))
		return (check_status_empty_line(state));
	if (state == STATE_CHECK_ANT)
		return (check_nb_ant(current_line, env));
	else if (state == STATE_CHECK_ROOM)
	{
		// In this function add the creation of tab of name, in order they are listed
		// The index will be use for the resoltion libgraph
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
