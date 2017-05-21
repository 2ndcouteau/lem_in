/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nb_ant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoko <yoko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 02:53:26 by yoko              #+#    #+#             */
/*   Updated: 2017/05/21 19:51:56 by yoko             ###   ########.fr       */
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

static bool	check_ascii_n_range(char *str, char *model, int len)
{
	int	i;

	i = 0;
	while (i < len)
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

	len = 0;
	while (!ft_isthischar(" \t\0", current_line[len]))
		len++;
	if (len > 9)
	{
		if (len == 10)
		{
			if (!check_ascii_n_range(current_line, "2147483647", len))
				return (SUCCESS);
		}
		return (ERROR);
	}
	return (SUCCESS);
}

static bool	ft_isnumber_spe(char *str)
{
	int i;

	i = 0;
	while (!ft_isnthischar(" \t\0", str[i]))
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (ERROR);
	}
	return (SUCCESS);
}

char		check_nb_ant(char *current_line, t_env **env)
{
	int i;

	i = 0;
	if (current_line[0] == '#')
		return (check_special_ant_line(current_line));
	while (ft_isthischar(" \t", current_line[i]))
		i++;
	if (ft_isnumber_spe(current_line + i))
		return (ERR_NB_ANT);
	if (check_max_int(current_line + i))
		return (ERR_ANT_OVERFLOW);
	(*env)->nb_ant = ft_atoi(current_line + i);
	if ((*env)->nb_ant == 0)
		return (ERR_NO_ANT);
	if (buff_add_str(env, current_line + i))
		return (ERR_MAP_SCALE);
	return (STATE_CHECK_ROOM);
}
