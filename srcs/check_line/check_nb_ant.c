/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nb_ant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoko <yoko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 02:53:26 by yoko              #+#    #+#             */
/*   Updated: 2017/05/16 03:33:00 by yoko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static bool	check_ascii_range(char *str, char *model)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] > model[i])
			return (ERROR);
		++i;
	}
	return (SUCCESS);
}

static char	check_max_int(char *current_line)
{
	int len;

	if ((len = ft_strlen(current_line)) > 9)
	{
		if (len == 10)
		{
			if (!check_ascii_range(current_line, "2147483647"))
				return (SUCCESS);
		}
		return (ERROR);
	}
	return (SUCCESS);
}

char		check_nb_ant(char *current_line, t_env **env)
{
	if (ft_isnumber(current_line))
		return (ERR_NB_ANT);
	if (check_max_int(current_line))
		return (ERR_ANT_OVERFLOW);
	(*env)->nb_ant = ft_atoi(current_line);
	if ((*env)->nb_ant == 0)
		return (ERR_NO_ANT);
	return (STATE_CHECK_ROOM);
}
