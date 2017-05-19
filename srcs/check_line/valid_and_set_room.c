/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_and_set_room.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 16:15:27 by qrosa             #+#    #+#             */
/*   Updated: 2017/05/20 00:26:41 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char		valid_and_set_room(char *current_line, t_env **env)
{
	int 	i;
	char	ret;

	i = 0;
	if ((ret = check_name_room(current_line, env, &i)) != SUCCESS)
		return (ret);
	if (current_line[i] == '\0')
		return (ERR_NO_COOR);
	if ((ret = check_coor_room(current_line, env, &i)) != SUCCESS)
		return (ret);
	// Free coor hashtab  final version
	return (SUCCESS);
}
