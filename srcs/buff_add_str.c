/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff_add_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoko <yoko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 14:58:27 by qrosa             #+#    #+#             */
/*   Updated: 2017/06/27 10:46:16 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Add the current line to the save map for the final print map.
**	+1 is for count '\n' for each new_line.
*/

static bool	realloc_buff_str(t_env **env, char *current_line)
{
	unsigned int	len;

	len = ft_strlen(current_line);
	if (((*env)->pos_map + len + 1) > (*env)->len_map)
	{
		while ((*env)->len_map < ((*env)->pos_map + len + 1))
			(*env)->len_map *= 2;
		if (!((*env)->save_map = ft_realloc((*env)->save_map, (*env)->len_map)))
			return (ERROR);
	}
	return (SUCCESS);
}

static void	copy_trim_str(t_env **env, char *current_line,
													t_uint r_pos, t_uint w_pos)
{
	while (current_line[r_pos] != '\0')
	{
		if (current_line[r_pos] == ' ' || current_line[r_pos] == '\t')
		{
			while (current_line[r_pos] == ' ' || current_line[r_pos] == '\t')
				r_pos++;
			if (w_pos > 0 && current_line[r_pos] != '\0')
			{
				(*env)->save_map[(*env)->pos_map + w_pos] = ' ';
				w_pos++;
			}
		}
		else
		{
			(*env)->save_map[(*env)->pos_map + w_pos] = current_line[r_pos];
			r_pos++;
			w_pos++;
		}
	}
	(*env)->save_map[(*env)->pos_map + w_pos] = '\n';
	(*env)->pos_map += w_pos + 1;
}

bool		buff_add_str(t_env **env, char *current_line)
{
	unsigned int	r_pos;
	unsigned int	w_pos;

	w_pos = 0;
	r_pos = 0;
	if (realloc_buff_str(env, current_line))
		return (ERROR);
	copy_trim_str(env, current_line, r_pos, w_pos);
	return (SUCCESS);
}
