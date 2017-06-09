/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 16:11:04 by qrosa             #+#    #+#             */
/*   Updated: 2017/06/09 01:25:10 by yoko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
