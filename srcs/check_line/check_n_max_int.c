/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_n_max_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 22:47:13 by qrosa             #+#    #+#             */
/*   Updated: 2017/05/19 22:47:28 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static bool	check_n_ascii_range(char *str, char *model, int start, int len)
{
	int pos;

	pos = 0;
	while (pos < len)
	{
		if (str[start + pos] > model[pos])
			return (ERROR);
		++pos;
	}
	return (SUCCESS);
}

char	check_n_max_int(char *current_line, int start, int len)
{
	if (len > 9)
	{
		if (len == 10)
		{
			if (!check_n_ascii_range(current_line, "2147483647", start, len))
				return (SUCCESS);
		}
		return (ERROR);
	}
	return (SUCCESS);
}
