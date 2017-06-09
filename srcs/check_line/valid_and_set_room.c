/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_and_set_room.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 16:15:27 by qrosa             #+#    #+#             */
/*   Updated: 2017/06/09 18:03:43 by yoko             ###   ########.fr       */
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
	// if ((*env)->tab_coor != NULL)
	//  	(*env)->tab_coor = free_hashtab(env, 1);
	return (SUCCESS);
}
