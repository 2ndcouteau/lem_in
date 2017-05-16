/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoko <yoko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 01:33:49 by yoko              #+#    #+#             */
/*   Updated: 2017/05/16 15:42:31 by yoko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	check_name_room(char *current_line, t_env **env)
{
	int		i;
//	char	split;
//	char	special;

	i = 1;
//	special = ROOM_NORMAL;
	if (current_line[0] == 'L')
		return (ERR_NAME_ROOM_L);
	// if (current_line[0] == '#')
	// 	special = check_
	while (current_line[i] != '\0')
	{
		if (current_line[i] == '-')
			return(STATE_CHECK_LINK);
		++i;
	}
	if (buff_add_str(env, current_line))
		return (ERR_MAP_SCALE);
	return (STATE_CHECK_ROOM);
}

// 2 cases:
// -- 1) The current line is a room
//							valid or not valid
// -- 2) The current line is a link
//							so state need to change

char	check_line(char state, char *current_line, t_env **env)
{
	ft_putendl(current_line); // DEBUG
	if (ft_is_empty_line(current_line))
		return (check_status_empty_line(state));
	if (state == STATE_CHECK_ANT)
		return (check_nb_ant(current_line, env));
	else if (state == STATE_CHECK_ROOM)
	{
		if ((state = check_name_room(current_line, env)) <= STATE_CHECK_ROOM)
			return (state);
	}
	if (state == STATE_CHECK_LINK)
	{
		if (buff_add_str(env, current_line))
			return (ERR_MAP_SCALE);
//		ft_putendl("check_links");
	}
	return (state);
}
