/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoko <yoko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 00:58:53 by yoko              #+#    #+#             */
/*   Updated: 2017/06/09 04:43:58 by yoko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	check_special_link_line(char *current_line, t_env **env)
{
	if (current_line[1] == '#')
	{
		if (!ft_strncmp((current_line + 2), "start", 6))
			(*env)->special_room = SPE_START_ROOM;
		else if (!ft_strncmp((current_line + 2), "end", 4))
			(*env)->special_room = SPE_END_ROOM;
		else
			return (STATE_CHECK_LINK);
		if (buff_add_str(env, current_line))
			return (ERR_MAP_SCALE);
	}
	return (STATE_CHECK_LINK);
}

char		check_links(char *current_line, t_env **env)
{
	int		i;
	char	ret;

	i = 0;
	if (current_line[0] == '#')
		return (check_special_link_line(current_line, env));
	while (!ft_isthischar(" \t", current_line[i]))
		i++;
	if ((ret = valid_and_set_links((current_line + i), env)) != SUCCESS)
		return (ret);
	(*env)->nb_link++;
	if (buff_add_str(env, current_line))
		return (ERR_MAP_SCALE);
	return (STATE_CHECK_LINK);
}

	/* For links
		You need to clean this part, and put all this error check in one function
		Then, check all links
			check name links
				if name is not compliante return error
					OK) L start
					OK) Dash start
					OK) multiple Dash ERROR
					OK) space or tabulation separator ERROR
				if name does not exist return error
					OK) check in hashtab
	*/