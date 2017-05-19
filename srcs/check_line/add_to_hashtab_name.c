/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_hashtab_name.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 16:19:14 by qrosa             #+#    #+#             */
/*   Updated: 2017/05/19 17:19:17 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static bool	set_special_room(char *name_room, t_env **env)
{
	if ((*env)->special_room == SPE_BASIC_ROOM)
		return (SUCCESS);
	else if ((*env)->special_room == SPE_START_ROOM)
	{
		(*env)->special_room = SPE_BASIC_ROOM;
		if (!((*env)->start_room = ft_strdup(name_room)))
			return (ERROR);
	}
	else
	{
		(*env)->special_room = SPE_BASIC_ROOM;
		if (!((*env)->end_room = ft_strdup(name_room)))
			return (ERROR);
	}
	return (SUCCESS);
}

static bool	insert_in_hashtab(t_hash *node, t_env **env, u_long hash_value)
{
	t_hash			*list;

	if ((*env)->tab_rooms[hash_value % HASHTAB_SIZE_NAME] == NULL)
		(*env)->tab_rooms[hash_value % HASHTAB_SIZE_NAME] = node;
	else
	{
		list = (*env)->tab_rooms[hash_value % HASHTAB_SIZE_NAME];
		while (list->next != NULL)
		{
			if (!ft_strcmp(list->room_name, node->room_name))
				return (ERROR);
			list = list->next;
		}
		if (!ft_strcmp(list->room_name, node->room_name))
			return (ERROR);
		list->next = node;
	}
	return (SUCCESS);
}

char		add_to_hashtab_name(char *current_line, t_env **env, int len_name)
{
	unsigned long	hash_value;
	char			*name_room;
	t_hash			*new_node;

//	ft_putendl("---- hash_tab_fct ----");  // DEBUG
	name_room = ft_strndup(current_line, 0, (len_name - 1));
	hash_value = hash_djb2((unsigned char *)name_room);
	if (!(new_node = (t_hash*)malloc(sizeof(t_hash))))
		return (ERR_CREATE_NODE);
	new_node->room_name = name_room;
	new_node->next = NULL;
	if (set_special_room(name_room, env))
		return (ERR_SPE_ROOM);
	if (insert_in_hashtab(new_node, env, hash_value))
		return (ERR_ROOM_EXIST);
	name_room = NULL;
	new_node = NULL;
	return (SUCCESS);
}
