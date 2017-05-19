/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_coor_room.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 22:49:26 by qrosa             #+#    #+#             */
/*   Updated: 2017/05/19 22:49:48 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static char		check_coor_x(char *current_line, int *i, int *coor_x)
{
	int 	cpt;

	cpt = 0;
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
	int 	cpt;

	cpt = 0;
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

char		check_coor_room(char *current_line, t_env **env, int *i)
{
	int		coor_x;
	int		coor_y;
	char	ret;

	if ((ret = check_coor_x(current_line, i, &coor_x)) != SUCCESS)
		return (ret);
	*i = browse_space(current_line, *i);
	if ((ret = check_coor_y(current_line, i, &coor_y)) != SUCCESS)
		return (ret);
	*i = browse_space(current_line, *i);
	if (current_line[*i] != '\0') // env Compilation condition tmp
		return (ERR_NAME_ROOM);
	if (env)
		ft_putchar('\n');
	// {
	// 	ft_putnbr(coor_x);
	// 	ft_putchar('\n');
	// 	ft_putnbr(coor_y);
	// 	ft_putchar('\n');
	// }

	// Need check double coordinates
	// Then save_coor
	return (SUCCESS);
}
