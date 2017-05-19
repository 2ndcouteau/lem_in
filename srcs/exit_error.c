/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoko <yoko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 23:54:06 by yoko              #+#    #+#             */
/*   Updated: 2017/05/19 23:40:27 by qrosa            ###   ########.fr       */
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
			if ((*env)->nb_room == 0)
				ft_putendl("ERROR : There is no room.");
		}
		else if (status == STATE_CHECK_LINK)
		{
			if ((*env)->nb_link == 0)
				ft_putendl("ERROR : There is no link.");
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
		else if (status == ERR_ADD_HASH)
			ft_putendl("\" failed to add the line to the hastab.");
		else if (status == ERR_ANT_START)
			ft_putendl("\" ants need to be set before ##start_room.");
		else if (status == ERR_ANT_END)
			ft_putendl("\" ants need to be set before ##end_room.");
		else if (status == ERR_NO_COOR)
			ft_putendl("\" the coordinates are missing.");
		else if (status == ERR_CREATE_NODE)
			ft_putendl("\" failed to create a new node in name_room hashtable.");
		else if (status == ERR_SPE_ROOM)
			ft_putendl("\" failed to set special room. {start, end}");
		else if (status == ERR_ROOM_EXIST)
			ft_putendl("\" The room already exists.");
		else if (status == ERR_NO_ROOM)
			ft_putendl("\" There is no room before links.");
		else if (status == ERR_MORE_ROOM)
			ft_putendl("\" need at least, one more room.");
		else if (status == ERR_SET_START)
			ft_putendl("\" ##start room is not set.");
		else if (status == ERR_SET_END)
			ft_putendl("\" ##end room is not set.");
		else if (status == ERR_NOTHING)
			ft_putendl("\" There is nothing to read.");
		else if (status == ERR_BAD_X_COOR)
			ft_putendl("\" X coordinate is not compliant.");
		else if (status == ERR_COOR_X_OVERFLOW)
			ft_putendl("\" X coordinate overflow.");
		else if (status == ERR_NO_Y_COOR)
			ft_putendl("\" There is no Y coordinate.");
		else if (status == ERR_BAD_Y_COOR)
			ft_putendl("\" Y coordinate is not compliant.");
		else if (status == ERR_COOR_Y_OVERFLOW)
			ft_putendl("\" Y coordinate overflow.");
		else if (status == ERR_CREATE_NODE_COOR)
			ft_putendl("\" Failed to create a new node in coor_room hastable.");
		else if (status == ERR_COOR_EXIST)
			ft_putendl("\" The coordinates already used.");
		else
			ft_putendl("\" invalid line");
		current_line = ft_free_line(&current_line);
	}
	free_struct(env);
//	exit(status);
	exit(EXIT_FAILURE);
}
