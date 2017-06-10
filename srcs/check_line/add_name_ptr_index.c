/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_name_ptr_index.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoko <yoko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 17:58:36 by yoko              #+#    #+#             */
/*   Updated: 2017/06/10 02:38:08 by yoko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static char	realloc_index_room(t_env **env)
{
	char			**new_index;
	unsigned int	i;
	unsigned int	size_tab;

	i = 0;
	size_tab = ((*env)->nb_room + 1) * 2;
	if (!(new_index = (char **)malloc(sizeof(char *) * size_tab)))
		return (ERROR);
	while (i < (*env)->nb_room)
	{
		new_index[i] = (*env)->index_room[i];
		i++;
	}
	while (i < size_tab)
	{
		new_index[i] = NULL;
		i++;
	}
	free((*env)->index_room);
	(*env)->index_room = new_index;
	new_index = NULL;
	return (SUCCESS);
}

char		add_name_ptr_index(t_env **env, char *room_name)
{
	if ((*env)->index_room != NULL)
	{
		if ((*env)->nb_room != 0 && (((*env)->nb_room + 1) % LEN_INDEX_ROOM) == 0)
		{
			if (realloc_index_room(env) == ERROR)
				return (ERR_REALLOC_INDEX_ROOM);
		}
		(*env)->index_room[(*env)->nb_room] = room_name;
		return (SUCCESS);
	}
	return (ERR_ADD_NAME_INDEX);
}
