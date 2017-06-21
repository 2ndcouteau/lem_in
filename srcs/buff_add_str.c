/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff_add_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoko <yoko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 14:58:27 by yoko              #+#    #+#             */
/*   Updated: 2017/06/21 11:39:17 by yoko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Add the current line to the save map for the final print map.
**	+1 is for count '\n' for each new_line.
*/
bool	buff_add_str(t_env **env, char *current_line)
{
	unsigned int	len;
	unsigned int	pos;

	pos = 0;
	len = ft_strlen(current_line);
	if (((*env)->pos_map + len + 1) > (*env)->len_map)
	{
		while ((*env)->len_map < ((*env)->pos_map + len + 1))
			(*env)->len_map *= 2;
		if (!((*env)->save_map = ft_realloc((*env)->save_map, (*env)->len_map)))
			return (ERROR);
	}
	while (pos < len)
	{
		(*env)->save_map[(*env)->pos_map + pos] = current_line[pos];
		pos++;
	}
	(*env)->save_map[(*env)->pos_map + pos] = '\n';
	(*env)->pos_map += len + 1;
	return (SUCCESS);
}
