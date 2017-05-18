/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoko <yoko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 01:33:49 by yoko              #+#    #+#             */
/*   Updated: 2017/05/18 01:51:41 by yoko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	"start" and "end" can not have white space after them in the line;
*/
char	check_special_line(char *current_line, t_env **env)
{
	if (current_line[1] == '#')
	{
		if (!ft_strncmp((current_line + 2), "start", 6))
			(*env)->special_room = SPE_START_ROOM;
		else if (!ft_strncmp((current_line + 2), "end", 4))
			(*env)->special_room = SPE_END_ROOM;
		else
			return (STATE_CHECK_ROOM);
		if (buff_add_str(env, current_line))
			return (ERR_MAP_SCALE);
	}
	return (STATE_CHECK_ROOM);
}

// static char	space_define(char word)
// {
// 	if (word < SPACE_CHARS_1)
// 	{
// 		if (word == NAME_ROOM)
// 			return (SPACE_CHARS_1);
// 		else if (word == COOR_X)
// 			return (SPACE_CHARS_2);
// 		else
// 			return (SPACE_CHARS_END);
// 	}
// 	if (word == SPACE_CHARS_1)
// 		return (COOR_X);
// 	else if (word == SPACE_CHARS_2)
// 		return (COOR_Y);
// }

char	check_valid_room_name(char *current_line, t_env **env, int *len_dup)
{
	int 	i;
	char	word;

	i = 0;
	word = NAME_ROOM;
	env = env; // Compilation condition
// START Valid name
	while (current_line[i] != '\0' && (word < COOR_X))
	{
//		word = space_define(word);
		if (current_line[i] == '\t' || current_line[i] == ' ')
			word = SPACE_CHARS_1;
		if (word == NAME_ROOM)
		{
			if (current_line[i] == '-')
			{
				*len_dup = LINK_LINE;
				return (SUCCESS);
			}
			*len_dup += 1;
		}
		else if (word == SPACE_CHARS_1)
		{
			if (current_line[i] != '\t' || current_line[i] != ' ')
				word = COOR_X;
		}
		i++;
	}
// END valid name
	if (current_line[i] == '\0')
		return (ERR_NO_COOR);
	return (SUCCESS);
}

char	check_name_room(char *current_line, t_env **env)
{
	int		len_dup;
	char	ret;

	len_dup = 0;
	if (current_line[0] == 'L')
		return (ERR_NAME_ROOM_L);
	if (current_line[0] == '#')
		return (check_special_line(current_line, env));
// Maybe you can add the name_room and coordinates directly in check_valid_room_name()
// if necessary, rename the functions to valid_set_room()
	if ((ret = check_valid_room_name(current_line, env, &len_dup)) != SUCCESS)
		return (ret);
	if (len_dup == LINK_LINE)
		return (STATE_CHECK_LINK);
	// if (add_to_hashtab(current_line, env, len_dup))
	// 	return (ERR_ADD_HASH);
	if (buff_add_str(env, current_line))
		return (ERR_MAP_SCALE);
	return (STATE_CHECK_ROOM);
}

// 2 cases:
// -- 1) The current line is a room
//							valid or not valid
// -- 2) The current line is a link
//							so state need to change

char	check_line(char state, char *current_line, t_env **env)
{
	ft_putendl(current_line); // DEBUG
	if (ft_is_empty_line(current_line))
		return (check_status_empty_line(state));
	if (state == STATE_CHECK_ANT)
		return (check_nb_ant(current_line, env));
	else if (state == STATE_CHECK_ROOM)
	{
		if ((state = check_name_room(current_line, env)) <= STATE_CHECK_ROOM)
			return (state);
	}
	if (state == STATE_CHECK_LINK)
	{
		if (buff_add_str(env, current_line))
			return (ERR_MAP_SCALE);
//		ft_putendl("check_links");
	}
	return (state);
}
