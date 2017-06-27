/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 10:22:26 by qrosa             #+#    #+#             */
/*   Updated: 2017/06/27 10:23:55 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_ants(t_ant *ants, unsigned long lemins, t_env *env)
{
	unsigned long	i;

	i = 0;
	while (i < (lemins + 1))
	{
		if (ants[i].path)
		{
			ft_putchar('L');
			ft_putnbr((int)i);
			ft_putchar('-');
			ft_putstr(env->index_room[(int)(int)ants[i].path->path[
												(int)ants[i].path_position]]);
			ft_putchar(' ');
		}
		++i;
	}
	ft_putchar('\n');
}
