/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:15:10 by qrosa             #+#    #+#             */
/*   Updated: 2017/06/27 12:52:07 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = (char*)b;
	while (i < len)
	{
		str[i] = (char)c;
		i++;
	}
	return (b);
}
