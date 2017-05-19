/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 22:42:49 by qrosa             #+#    #+#             */
/*   Updated: 2017/05/19 22:43:17 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	browse_space(char *current_line, int i)
{
	while ((current_line[i] == '\t' || current_line[i] == ' ') &&\
	current_line[i] != '\0')
		i++;
	return (i);
}
