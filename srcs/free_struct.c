/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoko <yoko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 23:55:55 by yoko              #+#    #+#             */
/*   Updated: 2017/05/17 22:21:41 by yoko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	*free_list(t_hash *node)
{
	t_hash	*tmp;

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

static void	*free_hash_tab(t_env **env)
{
	int i;

	i = 0;
	while (i < HASH_TAB_SIZE)
	{
		if ((*env)->tab_rooms[i] != NULL)
			(*env)->tab_rooms[i] = free_list((*env)->tab_rooms[i]);
		++i;
	}
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
			if ((*env)->start_room != NULL)
				(*env)->start_room = ft_free_line(&((*env)->start_room));
			if ((*env)->end_room != NULL)
				(*env)->end_room = ft_free_line(&((*env)->end_room));
			if ((*env)->tab_rooms != NULL)
			 	(*env)->tab_rooms = free_hash_tab(env);
			free(*env);
			*env = NULL;
		}
	}
}
