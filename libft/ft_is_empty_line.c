/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_empty_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 19:18:39 by qrosa             #+#    #+#             */
/*   Updated: 2017/06/27 12:37:57 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

bool	ft_is_empty_line(char *line)
{
	int i;

	i = 0;
	if (line != NULL)
	{
		while (line[i] != '\0')
		{
			if (line[i] > 32 && line[i] < 127)
				return (0);
			i++;
		}
		return (1);
	}
	return (1);
}
