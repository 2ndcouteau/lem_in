/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff_add_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoko <yoko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 14:58:27 by yoko              #+#    #+#             */
/*   Updated: 2017/05/16 15:14:21 by yoko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


/*
**	+1 is for count '\n' for each new_line.
*/
bool	buff_add_str(t_env **env, char *current_line)
{
	int	len;
	int	pos;

	pos = 0;
	len = ft_strlen(current_line);
	if (((*env)->pos_map + len + 1) > (*env)->len_map)
	{
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
