/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoko <yoko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 23:53:00 by yoko              #+#    #+#             */
/*   Updated: 2017/05/21 06:52:46 by yoko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_hash	**init_hashtable_name(void)
{
	t_hash		**tab;
	int			i;

	i = 0;
	if (!(tab = (t_hash**)malloc(sizeof(t_hash*) * HASHTAB_SIZE_NAME)))
		return (NULL);
	while (i < HASHTAB_SIZE_NAME)
	{
		tab[i] = NULL;
		++i;
	}
	return (tab);
}

static t_hash_coor	**init_hashtable_coor(void)
{
	t_hash_coor	**tab;
	int			i;

	i = 0;
	if (!(tab = (t_hash_coor**)malloc(sizeof(t_hash_coor*) * HASHTAB_SIZE_COOR)))
		return (NULL);
	while (i < HASHTAB_SIZE_COOR)
	{
		tab[i] = NULL;
		++i;
	}
	return (tab);
}

t_env 			*init_struct(void)
{
	t_env		*env;

	if (!(env = (t_env*)malloc(sizeof(t_env))))
		return (NULL);
	env->len_map = LEN_SAVE_MAP_INIT;
	env->save_map = ft_memalloc(LEN_SAVE_MAP_INIT);
	env->pos_map = 0;
	env->nb_ant = 0;
	env->nb_room = 0;
	env->nb_link = 0;
	env->special_room = SPE_BASIC_ROOM;
	env->start_room = NULL;
	env->end_room = NULL;
	env->tab_rooms = init_hashtable_name();
	env->tab_coor = init_hashtable_coor();
	return (env);
}
