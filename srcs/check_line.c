/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoko <yoko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 01:33:49 by yoko              #+#    #+#             */
/*   Updated: 2017/05/16 01:42:28 by yoko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// bool	check_name_room(char *current_line)
// {
// 	int i;
//
// 	i = 1;
// 	current_line[0] == 'L';
// 		return (ERROR);
// 	while (current_line[i] != '\0')
// 	{
// 		if (current_line[i] == )
// 		++i;
// 	}
// 	return (SUCCESS);
// }

char	check_nb_ant(char *current_line, t_env **env)
{
	if (ft_isnumber(current_line))
		return (ERR_NB_ANT);
	(*env)->nb_ant = ft_atoi(current_line);
	return (STATE_NB_ANT_OK);
}

char	check_line(int state, char *current_line, t_env **env)
{
	ft_putendl(current_line); // DEBUG
	if (state == 0)
		return (check_nb_ant(current_line, env));
	// else if (state == 1)
	// 	check_name_room(current_line);
	// else if (state == 2)
	// 	ft_putendl("check_links");
	return (state);
}
