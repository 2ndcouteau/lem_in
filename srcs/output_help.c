/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 15:39:55 by qrosa             #+#    #+#             */
/*   Updated: 2017/05/11 16:31:53 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

bool	output_help(bool return_value)
{
	ft_putendl("lem_in -- anthill manager.\n./lem_in < [FILE]");
	return (return_value);
}
