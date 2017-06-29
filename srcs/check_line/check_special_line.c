/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_special_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoko <yoko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 01:24:55 by qrosa             #+#    #+#             */
/*   Updated: 2017/06/26 17:49:22 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	check_special_line(char *current_line, t_env **env)
{
	int	pos;

	if (current_line[1] == '#')
	{
		if (!ft_strncmp((current_line + 2), "start", 5))
			(*env)->special_room = SPE_START_ROOM;
		else if (!ft_strncmp((current_line + 2), "end", 3))
			(*env)->special_room = SPE_END_ROOM;
		else
			return (STATE_CHECK_ROOM);
		if ((*env)->special_room == SPE_START_ROOM)
			pos = 7;
		else
			pos = 5;
		while (current_line[pos] != '\0')
		{
			if (current_line[pos] != ' ' && current_line[pos] != '\t')
				return (STATE_CHECK_ROOM);
			pos++;
		}
		if (buff_add_str(env, current_line))
			return (ERR_MAP_SCALE);
	}
	return (STATE_CHECK_ROOM);
}
