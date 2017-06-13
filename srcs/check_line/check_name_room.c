/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name_room.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 16:19:14 by qrosa             #+#    #+#             */
/*   Updated: 2017/06/10 04:35:33 by yoko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "../../includes/lem_in.h"

static bool	set_special_room(t_env **env)
{
	if ((*env)->special_room == SPE_BASIC_ROOM)
		return (SUCCESS);
	else if ((*env)->special_room == SPE_START_ROOM)
		(*env)->start_room = (*env)->nb_room;
	else
		(*env)->end_room = (*env)->nb_room;
	(*env)->special_room = SPE_BASIC_ROOM;
	return (SUCCESS);
}

static bool	insert_in_hashtab(t_hash *node, t_env **env, u_long hash_value)
{
	t_hash			*list;
	int				tmp;

	tmp = hash_value % HASHTAB_SIZE_NAME;		// can replace tmp by calcul in []
	if (tmp < 0)
		tmp = -tmp;
	if ((*env)->tab_rooms == NULL)	//  ??
		ft_putendl("TAB NULL");		// DEBUG
	if ((*env)->tab_rooms[tmp] == NULL)
		(*env)->tab_rooms[tmp] = node;
	else
	{
		list = (*env)->tab_rooms[tmp];
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

static char	add_to_hashtab_name(char *current_line, t_env **env, int len_name)
{
	unsigned long	hash_value;
	char			*name_room;
	t_hash			*new_node;
	char			ret;

	if (!(name_room = ft_strndup(current_line, 0, len_name)))
		return (ERR_CREATE_NODE);
	hash_value = hash_djb2((unsigned char *)name_room);
	if (!(new_node = (t_hash*)malloc(sizeof(t_hash))))
		return (ERR_CREATE_NODE);
	new_node->room_name = name_room;
	new_node->index_room = (*env)->nb_room;
	new_node->next = NULL;
	if ((ret = add_name_ptr_index(env, name_room)) != SUCCESS)
		return (ret);
	if (set_special_room(env))
		return (ERR_SPE_ROOM);
	if (insert_in_hashtab(new_node, env, hash_value))
		return (ERR_ROOM_EXIST);
	name_room = NULL;
	new_node = NULL;
	return (SUCCESS);
}

char		check_name_room(char *current_line, t_env **env, int *i)
{
	char	mark;
	char	ret;

	mark = 0;
	while (current_line[*i] != '\0' && mark == 0)
	{
		if (current_line[*i] == '\t' || current_line[*i] == ' ')
			mark = 1;
		else
		{
			if (current_line[*i] == '-')
				return (STATE_CHECK_FIRST_LINK);
			*i += 1;
		}
	}
	if ((ret = add_to_hashtab_name(current_line, env, *i)) != SUCCESS)
		return (ret);
	*i = browse_space(current_line, *i);
	return (SUCCESS);
}
