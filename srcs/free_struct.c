/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoko <yoko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 23:55:55 by yoko              #+#    #+#             */
/*   Updated: 2017/05/16 14:10:08 by yoko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_struct(t_env **env)
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
				(*env)->tab_rooms = ft_free_tab((*env)->tab_rooms);
			free(*env);
			*env = NULL;
		}
	}
}
