/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_clair_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 17:46:41 by qrosa             #+#    #+#             */
/*   Updated: 2017/06/27 12:53:34 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putendl_clair_fd(char const *s, int fd)
{
	if (s[0] != '.')
	{
		write(fd, s, ft_strlen(s));
		write(fd, "\n", 1);
	}
}
