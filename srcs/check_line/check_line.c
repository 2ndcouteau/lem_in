/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoko <yoko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 01:33:49 by yoko              #+#    #+#             */
/*   Updated: 2017/05/18 10:54:09 by qrosa            ###   ########.fr       */
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

char	add_to_hashtab(char *current_line, t_env **env, int len_name)
{
	unsigned long	hash_value;
	char			*name_room;
	t_hash			*new_node;
	t_hash			*list;

	ft_putendl("---- hash_tab_fct ----");
	name_room = ft_strndup(current_line, 0, len_name);
	hash_value = hash_djb2((unsigned char *)name_room);
	if (!(new_node = (t_hash*)malloc(sizeof(t_hash))))
		return (ERR_CREATE_NODE);
	new_node->room_name = name_room;
	new_node->next = NULL;
	name_room = NULL;
	if ((*env)->tab_rooms[hash_value % HASH_TAB_SIZE] == NULL)
		(*env)->tab_rooms[hash_value % HASH_TAB_SIZE] = new_node;
	else
	{
		list = (*env)->tab_rooms[hash_value % HASH_TAB_SIZE];
		while (list->next != NULL)
			list = list->next;
		list->next = new_node;
	}
	return (SUCCESS);
}

int		browse_space(char *current_line, char *word, int i)
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

char	check_valid_room_name(char *current_line, t_env **env)
{
	int 	i;
	char	word;
	char	ret;

	i = 0;
	word = NAME_ROOM;
// START Valid name
	while (current_line[i] != '\0' && (word == NAME_ROOM) && env) // "env" Compilation condition
	{
//		word = space_define(word);
		if (current_line[i] == '\t' || current_line[i] == ' ')
			word = SPACE_CHARS_1;
		if (word == NAME_ROOM)
		{
			if (current_line[i] == '-')
				return (STATE_CHECK_LINK);
		}
		i++;
	}
	if ((ret = add_to_hashtab(current_line, env, i)) != SUCCESS)
		return (ret);
// END valid name
	i = browse_space(current_line, &word, i);
	if (current_line[i] == '\0')
		return (ERR_NO_COOR);
	return (SUCCESS);
}

char	check_name_room(char *current_line, t_env **env)
{
	char	ret;

	if (current_line[0] == 'L')
		return (ERR_NAME_ROOM_L);
	if (current_line[0] == '#')
		return (check_special_line(current_line, env));
// Maybe you can add the name_room and coordinates directly in check_valid_room_name()
// if necessary, rename the functions to valid_set_room()
	if ((ret = check_valid_room_name(current_line, env)) != SUCCESS)
		return (ret);

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
