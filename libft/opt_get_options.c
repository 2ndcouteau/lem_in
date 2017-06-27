/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_get_options.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 20:55:19 by qrosa             #+#    #+#             */
/*   Updated: 2017/06/27 13:38:33 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	check_option_call(char *str, t_opt **e)
{
	if (str[1] == '-')
	{
		if (str[2] == '\0')
			return (1);
		if (ft_ispace_tab_line((*e)->define[2]))
			return (1);
	}
	else
	{
		if (str[1] == '\0')
			return (1);
		if (ft_ispace_tab_line((*e)->define[1]))
			return (1);
	}
	return (0);
}

static void	opt_exist(char *str, t_opt **e)
{
	if (str[1] == '-')
		opt_exist_long(str, e);
	else
		opt_exist_letter(str, e, 1, 0);
}

void		opt_get_options(int argc, char **argv, t_opt **e)
{
	while ((*e)->position < argc && (*e)->mark < 2)
	{
		if (argv[(*e)->position][0] == '-' && argv[(*e)->position][1] != '\0' &&
	check_option_call(argv[(*e)->position], e))
		{
			if (opt_is_valid(argv[(*e)->position], e))
			{
				if ((*e)->mark < 2)
					opt_exist(argv[(*e)->position], e);
			}
			else
				(*e)->mark = 2;
		}
		else
			opt_save_arg(argv[(*e)->position], e);
		(*e)->position++;
	}
}
