/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_status_empty_line.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoko <yoko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 02:47:57 by yoko              #+#    #+#             */
/*   Updated: 2017/05/16 02:48:15 by yoko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	check_status_empty_line(char status)
{
	if (status == STATE_CHECK_ANT)
		return (ERR_NB_ANT);
	else if (status == STATE_CHECK_ROOM)
		return (ERR_EMPTY_ROOM);
	else
		return (STATE_CHECK_END);
}
