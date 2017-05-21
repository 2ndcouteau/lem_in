/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_coor_room.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 22:49:26 by qrosa             #+#    #+#             */
/*   Updated: 2017/05/20 04:28:30 by yoko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static char		check_coor_x(char *current_line, int *i, int *coor_x)
{
	int 		cpt;

	cpt = 0;
	if (current_line[*i] == '-')
	{
		cpt++;
		*i += 1;
	}
	while (!ft_isdigit(current_line[*i]))
	{
		*i += 1;
		cpt++;
	}
	if (current_line[*i] != ' ' && current_line[*i] != '\t' && current_line[*i] != '\0')
		return (ERR_BAD_X_COOR);
	if (check_n_max_int(current_line, (*i - cpt), cpt) != SUCCESS)
		return (ERR_COOR_X_OVERFLOW);
	if (current_line[*i] == '\0')
		return (ERR_NO_Y_COOR);
	*coor_x = ft_atoi(current_line + (*i - cpt));
	return (SUCCESS);
}

static char		check_coor_y(char *current_line, int *i, int *coor_y)
{
	int 		cpt;

	cpt = 0;
	if (current_line[*i] == '-')
	{
		cpt++;
		*i += 1;
	}
	while (!ft_isdigit(current_line[*i]))
	{
		*i += 1;
		cpt++;
	}
	if (current_line[*i] != ' ' && current_line[*i] != '\t' && current_line[*i] != '\0')
		return (ERR_BAD_Y_COOR);
	if (check_n_max_int(current_line, (*i - cpt), cpt) != SUCCESS)
		return (ERR_COOR_Y_OVERFLOW);
	*coor_y = ft_atoi(current_line + (*i - cpt));
	return (SUCCESS);
}

static bool	insert_in_hashtab(t_hash_coor *node, t_env **env, int coor_x)
{
	t_hash_coor	*list;

	if ((*env)->tab_coor[coor_x % HASHTAB_SIZE_COOR] == NULL)
		(*env)->tab_coor[coor_x % HASHTAB_SIZE_COOR] = node;
	else
	{
		list = (*env)->tab_coor[coor_x % HASHTAB_SIZE_COOR];
		while (list->next != NULL)
		{
			if (list->x_coor == node->x_coor)
			{
				if (list->y_coor == node->y_coor)
					return (ERROR);
			}
			list = list->next;
		}
		if (list->x_coor == node->x_coor)
		{
			if (list->y_coor == node->y_coor)
				return (ERROR);
		}
		list->next = node;
	}
	return (SUCCESS);
}

static char	add_to_hashtab_coor(t_env **env, int coor_x, int coor_y)
{
	t_hash_coor *new_node;

	if (!(new_node = (t_hash_coor*)malloc(sizeof(t_hash_coor))))
		return (ERR_CREATE_NODE_COOR);
	new_node->x_coor = coor_x;
	new_node->y_coor = coor_y;
	new_node->next = NULL;
	if (insert_in_hashtab(new_node, env, coor_x))
		return (ERR_COOR_EXIST);
	new_node = NULL;
	return (SUCCESS);
}

char		check_coor_room(char *current_line, t_env **env, int *i)
{
	int			coor_x;
	int			coor_y;
	char		ret;

//	ft_putendl(current_line);
//	debug_struct(*env);
	if ((ret = check_coor_x(current_line, i, &coor_x)) != SUCCESS)
		return (ret);
	*i = browse_space(current_line, *i);
	if ((ret = check_coor_y(current_line, i, &coor_y)) != SUCCESS)
		return (ret);
	*i = browse_space(current_line, *i);
	if (current_line[*i] != '\0')
		return (ERR_NAME_ROOM);
	if ((ret = add_to_hashtab_coor(env, coor_x, coor_y)) != SUCCESS)
		return (ret);
	return (SUCCESS);
}
