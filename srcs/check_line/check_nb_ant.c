/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nb_ant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoko <yoko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 02:53:26 by yoko              #+#    #+#             */
/*   Updated: 2017/05/19 21:27:27 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static char	check_special_ant_line(char *current_line)
{
	if (current_line[1] == '#')
	{
		if (!ft_strncmp((current_line + 2), "start", 6))
			return (ERR_ANT_START);
		else if (!ft_strncmp((current_line + 2), "end", 4))
			return (ERR_ANT_END);
	}
	return (STATE_CHECK_ANT);
}

bool	check_ascii_range(char *str, char *model)
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
	if (current_line[0] == '#')
		return (check_special_ant_line(current_line));
	if (ft_isnumber(current_line))
		return (ERR_NB_ANT);
	if (check_max_int(current_line))
		return (ERR_ANT_OVERFLOW);
	(*env)->nb_ant = ft_atoi(current_line);
	if ((*env)->nb_ant == 0)
		return (ERR_NO_ANT);
	if (buff_add_str(env, current_line))
		return (ERR_MAP_SCALE);
	return (STATE_CHECK_ROOM);
}
