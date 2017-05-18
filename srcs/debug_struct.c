/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoko <yoko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 01:29:13 by yoko              #+#    #+#             */
/*   Updated: 2017/05/18 12:18:33 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	print_list(t_hash *list)
{
	while (list->next != NULL)
	{
		if (list->room_name != NULL)
			ft_putstr(list->room_name);
		else
			ft_putstr("-null-");
		ft_putstr(" - ");
		list = list->next;
	}
	if (list->room_name != NULL)
		ft_putendl(list->room_name);
	else
		ft_putendl("-null-");
}

static void	print_hashtable(t_hash **hashtab)
{
	int		len;

	len = 0;
	while (len < HASH_TAB_SIZE)
	{
		ft_putstr(ft_itoa(len));
		ft_putstr(": ");
		if (hashtab[len] != NULL)
			print_list(hashtab[len]);
		else
			ft_putendl("(null)");
		len++;
	}
}

void		print_elem(char *begin, char *elem)
{
	ft_putstr(begin);
	if (elem == NULL)
		ft_putendl("(null)");
	else
		ft_putendl(elem);
}

void		debug_struct(t_env *env)
{
	ft_putendl("\n################\n- DEBUG OUTPUT -\n################\n");
	if (env != NULL)
	{
		print_elem("Nb_ant == ", ft_itoa(env->nb_ant));
		print_elem("Nb_room == ", ft_itoa(env->nb_room));
		print_elem("Start room == ", env->start_room);
		print_elem("End room == ", env->end_room);
		ft_putendl("\n- Hashtable -\n");
		if (env->tab_rooms != NULL)
			print_hashtable(env->tab_rooms);
		else
			ft_putendl("tab_rooms = (null)");
	}
}
