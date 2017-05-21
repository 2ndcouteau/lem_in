/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoko <yoko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 23:54:06 by yoko              #+#    #+#             */
/*   Updated: 2017/05/21 14:21:33 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// Make a array plz !!!
int		exit_error(char status, char *current_line, t_env **env)
{
	if (status >= 0)
	{
		if (status == STATE_CHECK_ANT)
			ft_putendl_fd("ERROR : The map is empty.", 2);
		else if ((*env)->nb_room == 0)
			ft_putendl_fd("ERROR : There is no room.", 2);
		else if ((*env)->start_room == NULL)
			ft_putendl_fd("ERROR : There is no start room.", 2);
		else if ((*env)->end_room == NULL)
			ft_putendl_fd("ERROR : There is no end room.", 2);
		else if (status == STATE_CHECK_ROOM)
		{
			if ((*env)->nb_room == 0)
				ft_putendl_fd("ERROR : There is no room.", 2);
		}
		else if (status == STATE_CHECK_LINK)
		{
			if ((*env)->nb_link == 0)
				ft_putendl_fd("ERROR : There is no link.", 2);
		}
	}
	else
	{
		ft_putstr_fd("ERROR -- line:", 2);
		ft_putnbr_fd((*env)->nb_line, 2);
		ft_putstr_fd(" \"", 2);
		ft_putstr_fd(current_line, 2);
		if (status == ERR_NB_ANT)
			ft_putendl_fd("\" bad ant number.", 2);
		else if (status == ERR_NAME_ROOM)
			ft_putendl_fd("\" is not a valid room.", 2);
		else if (status == ERR_NAME_LINK)
			ft_putendl_fd("\" is not a valid link.", 2);
		else if (status == ERR_EMPTY_ROOM)
			ft_putendl_fd("\" is an empty room name.", 2);
		else if (status == ERR_ANT_OVERFLOW)
			ft_putendl_fd("\" ant number is too large.", 2);
		else if (status == ERR_NO_ANT)
			ft_putendl_fd("\" there is no ant. :(", 2);
		else if (status == ERR_MAP_SCALE)
			ft_putendl_fd("\" failed to increase map save buffer !", 2);
		else if (status == ERR_NAME_ROOM_L)
			ft_putendl_fd("\" room name can not start by \'L\'", 2);
		else if (status == ERR_FIRST_LINE_EMPTY)
			ft_putendl_fd("\" first line is empty.", 2);
		else if (status == ERR_ADD_HASH)
			ft_putendl_fd("\" failed to add the line to the hastab.", 2);
		else if (status == ERR_ANT_START)
			ft_putendl_fd("\" ants need to be set before ##start_room.", 2);
		else if (status == ERR_ANT_END)
			ft_putendl_fd("\" ants need to be set before ##end_room.", 2);
		else if (status == ERR_NO_COOR)
			ft_putendl_fd("\" the coordinates are missing.", 2);
		else if (status == ERR_CREATE_NODE)
			ft_putendl_fd("\" failed to create a new node in name_room hashtable.", 2);
		else if (status == ERR_SPE_ROOM)
			ft_putendl_fd("\" failed to set special room. {start, end}", 2);
		else if (status == ERR_ROOM_EXIST)
			ft_putendl_fd("\" The room already exists.", 2);
		else if (status == ERR_NO_ROOM)
			ft_putendl_fd("\" There is no room before links.", 2);
		else if (status == ERR_MORE_ROOM)
			ft_putendl_fd("\" need at least, one more room.", 2);
		else if (status == ERR_SET_START)
			ft_putendl_fd("\" ##start room is not set.", 2);
		else if (status == ERR_SET_END)
			ft_putendl_fd("\" ##end room is not set.", 2);
		else if (status == ERR_NOTHING)
			ft_putendl_fd("\" There is nothing to read.", 2);
		else if (status == ERR_BAD_X_COOR)
			ft_putendl_fd("\" X coordinate is not compliant.", 2);
		else if (status == ERR_COOR_X_OVERFLOW)
			ft_putendl_fd("\" X coordinate overflow.", 2);
		else if (status == ERR_NO_Y_COOR)
			ft_putendl_fd("\" There is no Y coordinate.", 2);
		else if (status == ERR_BAD_Y_COOR)
			ft_putendl_fd("\" Y coordinate is not compliant.", 2);
		else if (status == ERR_COOR_Y_OVERFLOW)
			ft_putendl_fd("\" Y coordinate overflow.", 2);
		else if (status == ERR_CREATE_NODE_COOR)
			ft_putendl_fd("\" Failed to create a new node in coor_room hastable.", 2);
		else if (status == ERR_COOR_EXIST)
			ft_putendl_fd("\" The coordinates are already used.", 2);
		else if (status == ERR_START_LINK)
			ft_putendl_fd("\" Start room can not be set with a link.", 2);
		else if (status == ERR_END_LINK)
			ft_putendl_fd("\" End room can not be set with a link.", 2);
		else
			ft_putendl_fd("\" invalid line", 2);
		current_line = ft_free_line(&current_line);
	}
	free_struct(env);
//	exit(status);
	exit(EXIT_FAILURE);
}
