/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoko <yoko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 23:54:06 by yoko              #+#    #+#             */
/*   Updated: 2017/06/09 17:55:19 by yoko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

const char *g_tab_error_toto[] =
{
	"\" Y coordinate is not compliant.",
	"\" Y coordinate overflow.",
	"\" Failed to create a new node in coor_room hastable.",
	"\" The coordinates are already used.",
	"\" Start room can not be set with a link.",
	"\" End room can not be set with a link.",
	"\" Link line must start by a room name.",
	"\" Link room name can not start by 'L'.",
	"\"	In link line, rooms must be separate by a dash: ROOM1-ROOM2",
	"\" First room name of the link is unknown.",
	"\" Link line must have only one dash: ROOM1-ROOM2.",
	"\" Second room name of the link is unknown.",
	"\" Fail to add room name in index table.",
	"\" Fail to realloc index room."
};

const char *g_tab_error_1[] =
{
	"\" bad ant number.",
	"\" is not a valid room.",
	"\" is not a valid link.",
	"\" is an empty room name.",
	"\" ant number is too large.",
	"\" there is no ant. :(",
	"\" failed to increase map save buffer !",
	"\" room name can not start by \'L\'",
	"\" first line is empty.",
	"\" failed to add the line to the hastab.",
	"\" ants need to be set before ##start_room.",
	"\" ants need to be set before ##end_room.",
	"\" the coordinates are missing.",
	"\" failed to create a new node in name_room hashtable.",
	"\" failed to set special room. {start, end}",
	"\" The room already exists.",
	"\" There is no room before links.",
	"\" need at least, one more room.",
	"\" ##start room is not set.",
	"\" ##end room is not set.",
	"\" There is nothing to read.",
	"\" X coordinate is not compliant.",
	"\" X coordinate overflow.",
	"\" There is no Y coordinate."
};

static void	end_file_errors(char status, t_env **env)
{
	if (status == STATE_CHECK_ANT)
		ft_putendl_fd("ERROR : The map is empty.", 2);
	else if ((*env)->nb_room == 0)
		ft_putendl_fd("ERROR : There is no room.", 2);
	else if ((*env)->start_room < 0)
		ft_putendl_fd("ERROR : There is no start room.", 2);
	else if ((*env)->end_room < 0)
		ft_putendl_fd("ERROR : There is no end room.", 2);
	else if (status == STATE_CHECK_ROOM)
	{
		if ((*env)->nb_room == 0)
			ft_putendl_fd("ERROR : There is no room.", 2);
		else if ((*env)->nb_link == 0)
			ft_putendl_fd("ERROR : There is no link.", 2);
	}
	else if (status == STATE_CHECK_LINK)
	{
		if ((*env)->nb_link == 0)
			ft_putendl_fd("ERROR : There is no link.", 2);
	}
}

int			exit_error(char status, char *current_line, t_env **env)
{
	if (status >= 0)
		end_file_errors(status, env);
	else
	{
		status = -status;
		ft_putstr_fd("ERROR -- line:", 2);
		ft_putnbr_fd((*env)->nb_line, 2);
		ft_putstr_fd(" \"", 2);
		ft_putstr_fd(current_line, 2);
		if (status < 25)
			ft_putendl_fd(g_tab_error_1[status - 1], 2);
		else if (status < LAST_ERROR)
			ft_putendl_fd(g_tab_error_toto[(status - 25)], 2);
		else
			ft_putendl_fd("\" invalid line", 2);

		current_line = ft_free_line(&current_line);
	}
	free_struct(env);
	if (status == 0)
		status += 1;
	exit(status);
}
