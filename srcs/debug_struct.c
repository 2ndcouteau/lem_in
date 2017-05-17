/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoko <yoko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 01:29:13 by yoko              #+#    #+#             */
/*   Updated: 2017/05/17 19:47:58 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	debug_struct(t_env *env)
{
	if (env != NULL)
	{
		printf("nb_ant == %d\n", env->nb_ant);
		printf("Start room == %s\n", env->start_room);
		printf("End room == %s\n", env->end_room);
		if (env->tab_rooms != NULL)
//			ft_put_tab(env->tab_rooms);
//		else
			ft_putendl("tab_rooms == (null)");
	}
}
