/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 22:41:00 by qrosa             #+#    #+#             */
/*   Updated: 2017/06/27 11:48:12 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libmatgraph.h"

void	delete_path(t_path **path)
{
	if (*path)
	{
		if ((*path)->path)
			free((*path)->path);
		(*path)->path = NULL;
		free(*path);
		*path = NULL;
	}
}
