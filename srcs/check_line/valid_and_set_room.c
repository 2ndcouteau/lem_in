/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_and_set_room.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 16:15:27 by qrosa             #+#    #+#             */
/*   Updated: 2017/05/19 17:26:06 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	browse_space(char *current_line, char *word, int i)
{
	while (current_line[i] != '\0' && (*word >= SPACE_CHARS_1))
	{
		if (current_line[i] != '\t' || current_line[i] != ' ')
		{
			if (*word == SPACE_CHARS_1)
				*word = COOR_X;
			else if (*word == SPACE_CHARS_2)
				*word = COOR_Y;
			return (i);
		}
		i++;
	}
	return (i);
}

char		valid_and_set_room(char *current_line, t_env **env)
{
	int 	i;
	char	word;
	char	ret;

	i = 0;
	word = NAME_ROOM;
// START Valid name
	while (current_line[i] != '\0' && (word == NAME_ROOM))
	{
		if (current_line[i] == '\t' || current_line[i] == ' ')
			word = SPACE_CHARS_1;
		if (word == NAME_ROOM)
		{
			if (current_line[i] == '-')
				return (STATE_CHECK_LINK);
		}
		i++;
	}
	if ((ret = add_to_hashtab_name(current_line, env, i)) != SUCCESS)
		return (ret);
// END valid name
	i = browse_space(current_line, &word, i);
	if (current_line[i] == '\0')
		return (ERR_NO_COOR);

	// Need check _coordinates !!
	return (SUCCESS);
}
