/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_and_set_links.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoko <yoko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 03:26:43 by yoko              #+#    #+#             */
/*   Updated: 2017/06/09 17:29:37 by yoko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static char	check_start_line_errors(char *current_line, t_env **env)
{
	if (current_line[0] == 'L')
		return (ERR_NAME_LINK_L);
	if (current_line[0] == '-')
		return (ERR_NO_BEGIN_NAME);
	if ((*env)->special_room == SPE_START_ROOM)
		return (ERR_START_LINK);
	else if ((*env)->special_room == SPE_END_ROOM)
		return (ERR_END_LINK);
	return (SUCCESS);
}

static char	valid_first_room(char *current_line, t_env **env, int *i)
{
	unsigned long	hash_value;
	char			*room_name;
	t_hash			*list;

	while (!ft_isnthischar(" \t-", current_line[*i]) && current_line[*i] != '\0')
		*i += 1;
	if (current_line[*i] != '-')
		return (ERR_FORMAT_LINK);
	room_name = ft_strndup(current_line, 0, *i);
	hash_value = hash_djb2((unsigned char *)room_name);
	if ((list = (*env)->tab_rooms[hash_value % HASHTAB_SIZE_NAME]) != NULL)
	{
		while (list != NULL)
		{
			if (!ft_strcmp(list->room_name, room_name))
			{
				(*env)->index_room1 = list->index_room;
				room_name = ft_free_line(&room_name);
				return (SUCCESS);
			}
			list = list->next;
		}
	}
	room_name = ft_free_line(&room_name);
	return (ERR_NAME_LINK1_NOMATCH);
}

static char browse_list_name(unsigned long hash_value, char *room_name, t_env **env)
{
	t_hash			*list;

	if ((list = (*env)->tab_rooms[hash_value % HASHTAB_SIZE_NAME]) != NULL)
	{
		while (list != NULL)
		{
			if (!ft_strcmp(list->room_name, room_name))
			{
				(*env)->index_room1 = list->index_room;
				return (SUCCESS);
			}
			list = list->next;
		}
	}
	return (ERR_NAME_LINK2_NOMATCH);
}

static char	valid_second_room(char *current_line, t_env **env, int *i)
{
	unsigned long	hash_value;
	char			*room_name;
	int				pos;
	char			ret;

	pos = *i;
	if (current_line[*i] == 'L')
		return (ERR_NAME_LINK_L);
	while (!ft_isnthischar(" \t-", current_line[*i]) && current_line[*i] != '\0')
		*i += 1;
	if (current_line[*i] == '-')
		return (ERR_DOUBLE_DASH);
	room_name = ft_strndup(current_line, pos, *i);
	hash_value = hash_djb2((unsigned char *)room_name);
	ret = browse_list_name(hash_value, room_name, env);
	room_name = ft_free_line(&room_name);
	return (ret);
}

char		valid_and_set_links(char *current_line, t_env **env)
{
	int 			i;
	char			ret;

	i = 0;
	if ((ret = check_start_line_errors(current_line, env)) != SUCCESS)
		return (ret);
	if ((ret = valid_first_room(current_line, env, &i)) != SUCCESS)
		return (ret);
	i += 1;
	if ((ret = valid_second_room(current_line, env, &i)) != SUCCESS)
		return (ret);
	i = browse_space(current_line, i);
	if (current_line[i] != '\0')
		return (ERR_FORMAT_LINK);
	return (SUCCESS);
}
