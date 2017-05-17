/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoko <yoko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 23:55:55 by yoko              #+#    #+#             */
/*   Updated: 2017/05/17 18:12:14 by qrosa            ###   ########.fr       */
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
			// if ((*env)->tab_rooms != NULL)						NEED to free hash tab;
			// 	(*env)->tab_rooms = free_hash_tab()
			free(*env);
			*env = NULL;
		}
	}
}
