/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_special_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoko <yoko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 01:24:55 by yoko              #+#    #+#             */
/*   Updated: 2017/06/09 01:25:29 by yoko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	"start" and "end" can not have white space after them in the line;
*/
		// SO MAYBE YOU CAN FIX THAT PLZ
char	check_special_line(char *current_line, t_env **env)
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
