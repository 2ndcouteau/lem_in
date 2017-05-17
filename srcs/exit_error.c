/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoko <yoko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 23:54:06 by yoko              #+#    #+#             */
/*   Updated: 2017/05/17 18:01:31 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// Make a array plz !!!
int		exit_error(char status, char *current_line, t_env **env)
{
	if (status >= 0)
	{
		if (status == STATE_CHECK_ANT)
			ft_putendl("ERROR : The map is empty.");
		else if ((*env)->nb_room == 0)
			ft_putendl("ERROR : There is no room.");
		else if ((*env)->start_room == NULL)
			ft_putendl("ERROR : There is no start room.");
		else if ((*env)->end_room == NULL)
			ft_putendl("ERROR : There is no end room.");
		else if (status == STATE_CHECK_ROOM)
		{
			ft_putendl("ERROR : The map is empty.");
		}
	}
	else
	{
		ft_putstr("ERROR : \"");
		ft_putstr(current_line);
		if (status == ERR_NB_ANT)
			ft_putendl("\" bad ant number.");
		else if (status == ERR_NAME_ROOM)
			ft_putendl("\" is not a valid room.");
		else if (status == ERR_NAME_LINK)
			ft_putendl("\" is not a valid link.");
		else if (status == ERR_EMPTY_ROOM)
			ft_putendl("\" is an empty room name.");
		else if (status == ERR_ANT_OVERFLOW)
			ft_putendl("\" ant number is too large.");
		else if (status == ERR_NO_ANT)
			ft_putendl("\" there is no ant. :(");
		else if (status == ERR_MAP_SCALE)
			ft_putendl("\" failed to increase map save buffer !");
		else if (status == ERR_NAME_ROOM_L)
			ft_putendl("\" room name can not start by \'L\'");
		else if (status == ERR_FIRST_LINE_EMPTY)
			ft_putendl("\" first line is empty.");
		else
			ft_putendl("\" invalid line");
		current_line = ft_free_line(&current_line);
	}
	free_struct(env);
//	exit(status);
	exit(EXIT_FAILURE);
}
