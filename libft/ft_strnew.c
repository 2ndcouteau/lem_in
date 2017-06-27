/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 16:51:09 by qrosa             #+#    #+#             */
/*   Updated: 2017/06/27 13:11:59 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	n;

	n = 0;
	if ((str = (char*)malloc(sizeof(char) * size)))
	{
		while (n < size)
		{
			str[n] = '\0';
			n++;
		}
		return (str);
	}
	return (NULL);
}
