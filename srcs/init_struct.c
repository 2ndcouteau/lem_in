/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoko <yoko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 23:53:00 by yoko              #+#    #+#             */
/*   Updated: 2017/05/17 17:44:52 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_hash	**init_hash_table(void)
{
	t_hash	**tab;
	int		i;

	i = 0;
	if (!(tab = (t_hash**)malloc(sizeof(t_hash*) * HASH_TAB_SIZE)))
		return (NULL);
	while (i < HASH_TAB_SIZE)
	{
		tab[i] = NULL;
		++i;
	}
	return (tab);
}

t_env 			*init_struct(void)
{
	t_env	*env;

	if (!(env = (t_env*)malloc(sizeof(t_env))))
		return (NULL);
	env->len_map = LEN_SAVE_MAP_INIT;
	env->save_map = ft_memalloc(LEN_SAVE_MAP_INIT);
	env->pos_map = 0;
	env->nb_ant = 0;
	env->nb_room = 0;
	env->nb_link = 0;
	env->start_room = NULL;
	env->end_room = NULL;
	env->tab_rooms = init_hash_table();
	return (env);
}
