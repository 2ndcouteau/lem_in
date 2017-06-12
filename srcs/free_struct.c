/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoko <yoko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 23:55:55 by yoko              #+#    #+#             */
/*   Updated: 2017/06/09 18:07:47 by yoko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	*free_list_name(t_hash *node)
{
	t_hash		*tmp;

	while (node != NULL)
	{
		tmp = node;
		node = node->next;
		tmp->room_name = ft_free_line(&(tmp->room_name));
		tmp->next = NULL;
		free(tmp);
	}
	tmp = NULL;
	return (NULL);
}

static void	*free_list_coor(t_hash_coor *node)
{
	t_hash_coor	*tmp;

	while (node != NULL)
	{
		tmp = node;
		node = node->next;
		tmp->next = NULL;
		free(tmp);
	}
	tmp = NULL;
	return (NULL);
}

void		*free_hashtab(t_env **env, bool type)
{
	int 		i;

	i = 0;
	if (type == 0)
	{
		while (i < HASHTAB_SIZE_NAME)
		{
			if ((*env)->tab_rooms[i] != NULL)
				(*env)->tab_rooms[i] = free_list_name((*env)->tab_rooms[i]);
			++i;
		}
		free((*env)->tab_rooms);
		return (NULL);
	}
	while (i < HASHTAB_SIZE_COOR)
	{
		if ((*env)->tab_coor[i] != NULL)
			(*env)->tab_coor[i] = free_list_coor((*env)->tab_coor[i]);
		++i;
	}
	free((*env)->tab_coor);
	return (NULL);
}

static void	*free_index_room(char **index_room)
{
	int			i;

	i = 0;
	while (index_room[i] != NULL)
	{
		index_room[i] = NULL;
		i++;
	}
	free(index_room);
	return (NULL);
}

void		free_struct(t_env **env)
{
	if (env != NULL)
	{
		if (*env != NULL)
		{
			if ((*env)->save_map != NULL)
				(*env)->save_map = ft_free_line(&((*env)->save_map));
			if ((*env)->index_room != NULL)
				(*env)->index_room = free_index_room((*env)->index_room);
			if ((*env)->tab_rooms != NULL)
			 	(*env)->tab_rooms = free_hashtab(env, 0);
			if ((*env)->tab_coor != NULL)
			 	(*env)->tab_coor = free_hashtab(env, 1);
			free(*env);
			*env = NULL;
		}
	}
}
