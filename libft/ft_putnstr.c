/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 11:46:28 by qrosa             #+#    #+#             */
/*   Updated: 2017/06/27 12:54:38 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnstr(char const *str, int n)
{
	int	len;

	if (str != NULL)
	{
		len = ft_strlen(str);
		if (n <= len)
			write(1, str, n);
	}
}
