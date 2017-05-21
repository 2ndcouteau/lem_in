/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 16:11:04 by qrosa             #+#    #+#             */
/*   Updated: 2017/05/21 16:41:48 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	"start" and "end" can not have white space after them in the line;
*/

static char	check_special_line(char *current_line, t_env **env)
{
	if (current_line[1] == '#')
	{
		if (!ft_strncmp((current_line + 2), "start", 6))
			(*env)->special_room = SPE_START_ROOM;
		else if (!ft_strncmp((current_line + 2), "end", 4))
			(*env)->special_room = SPE_END_ROOM;
		else
			return (STATE_CHECK_ROOM);
		if (buff_add_str(env, current_line))
			return (ERR_MAP_SCALE);
	}
	return (STATE_CHECK_ROOM);
}

char		check_room(char *current_line, t_env **env)
{
	char	ret;
	int		i;

	i = 0;
	if (current_line[0] == '#')
		return (check_special_line(current_line, env));
	while (!ft_isthischar(" \t", current_line[i]))
		i++;
	if (current_line[i] == 'L')
		return (ERR_NAME_ROOM_L);
	if ((ret = valid_and_set_room((current_line + i), env)) != SUCCESS)
		return (ret);
	(*env)->nb_room++;
	if (buff_add_str(env, (current_line + i)))
		return (ERR_MAP_SCALE);
	return (STATE_CHECK_ROOM);
}
