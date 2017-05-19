/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoko <yoko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 01:29:13 by yoko              #+#    #+#             */
/*   Updated: 2017/05/20 00:06:48 by qrosa            ###   ########.fr       */
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

void	print_hashtable(t_hash **hashtab)
{
	int		len;
	char	*tmp;

	len = 0;
	while (len < HASHTAB_SIZE_NAME)
	{
		tmp = ft_itoa(len);
		ft_putstr(tmp);
		free(tmp);
		tmp = NULL;
		ft_putstr(": ");
		if (hashtab[len] != NULL)
			print_list(hashtab[len]);
		else
			ft_putendl("(null)");
		len++;
	}
}

static void		print_elem(char *begin, char *elem)
{
	ft_putstr(begin);
	if (elem == NULL)
		ft_putendl("(null)");
	else
		ft_putendl(elem);
}

static void	print_list_coor(t_hash_coor *list)
{
	while (list != NULL)
	{
		ft_putnbr(list->x_coor);
		ft_putchar(':');
		ft_putnbr(list->y_coor);
		ft_putstr(" - ");
		list = list->next;
	}
	ft_putchar('\n');
}

void		print_hashtable_coor(t_hash_coor **hashtab)
{
	int		len;
	char	*tmp;

	len = 0;
	while (len < HASHTAB_SIZE_COOR)
	{
		tmp = ft_itoa(len);
		ft_putstr(tmp);
		free(tmp);
		tmp = NULL;
		ft_putstr(": ");
		if (hashtab[len] != NULL)
			print_list_coor(hashtab[len]);
		else
			ft_putendl("(null)");
		len++;
	}
}

void		debug_struct(t_env *env)
{
	char *tmp;
	ft_putendl("\n################\n- DEBUG OUTPUT -\n################\n");
	if (env != NULL)
	{
		tmp = ft_itoa(env->nb_ant);
		print_elem("Nb_ant == ", tmp);
		free(tmp);
		tmp = ft_itoa(env->nb_room);
		print_elem("Nb_room == ", tmp);
		free(tmp);
		print_elem("Start room == ", env->start_room);
		print_elem("End room == ", env->end_room);
		ft_putendl("\n- Hashtable Name Room -\n");
		if (env->tab_rooms != NULL)
			print_hashtable(env->tab_rooms);
		else
			ft_putendl("tab_rooms = (null)");
		ft_putendl("\n\n- Hashtable Coor Room -\n");
		if (env->tab_coor != NULL)
			print_hashtable_coor(env->tab_coor);
		else
			ft_putendl("tab_coor = (null)");
		tmp = NULL;
	}
}
