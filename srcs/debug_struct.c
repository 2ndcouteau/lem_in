/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoko <yoko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 01:29:13 by yoko              #+#    #+#             */
/*   Updated: 2017/05/18 11:08:19 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	print_list(t_hash *list)
{
	while (list->next != NULL)
	{
		ft_putstr(list->room_name);
		ft_putchar(' ');
	}
	ft_putstr(list->room_name);
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
			print_list(*hashtab);
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
	if (env != NULL)
	{
		print_elem("Nb_ant == ", ft_itoa(env->nb_ant));
		print_elem("Start room == ", env->start_room);
		print_elem("End room == ", env->end_room);
		if (env->tab_rooms != NULL)
			print_hashtable(env->tab_rooms);
		else
			ft_putendl("tab_rooms = (null)");
	}
}
