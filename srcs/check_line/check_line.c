/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoko <yoko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 01:33:49 by yoko              #+#    #+#             */
/*   Updated: 2017/05/16 02:53:41 by yoko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// bool	check_name_room(char *current_line, t_env **env)
// {
// 	int		i;
// 	char	special;
//
// 	i = 1;
// 	special = ROOM_NORMAL;
// 	current_line[0] == 'L';
// 		return (ERR_NAME_ROOM);
//
// 	if (current_line[0] == '#')
// 		special = check_
//
// 	while (current_line[i] != '\0')
// 	{
// 		if (current_line[i] == )
// 		++i;
// 	}
// 	return (SUCCESS);
// }

char	check_line(char state, char *current_line, t_env **env)
{
	ft_putendl(current_line); // DEBUG
	if (ft_is_empty_line(current_line))
		return (check_status_empty_line(state));
	if (state == STATE_CHECK_ANT)
		return (check_nb_ant(current_line, env));
	// else if (state == STATE_CHECK_ROOM)
	// {
	// 	if (check_name_room(current_line, env) == STATE_NAME_ROOM_OK)
	// 	return (
	// }

	// else if (state == STATE_CHECK_LINK)
	// 	ft_putendl("check_links");
	return (state);
}
