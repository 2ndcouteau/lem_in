/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoko <yoko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 23:54:06 by yoko              #+#    #+#             */
/*   Updated: 2017/05/16 03:34:12 by yoko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


// Make a array plz !!!
int		exit_error(char status, char *current_line, t_env **env)
{
	free_struct(env);
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
	current_line = ft_free_line(&current_line);
//	exit(status);
	exit(EXIT_FAILURE);
}
