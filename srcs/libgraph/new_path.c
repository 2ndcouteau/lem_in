/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 19:11:00 by qrosa             #+#    #+#             */
/*   Updated: 2017/06/27 12:00:28 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libmatgraph.h"

t_path	*new_path(unsigned long src, unsigned long dst)
{
	t_path	*path;

	path = NULL;
	if ((path = (t_path*)malloc(sizeof(t_path))))
	{
		path->src = src;
		path->dst = dst;
		path->len = 0;
		path->path = NULL;
	}
	return (path);
}
