/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:58:26 by qrosa             #+#    #+#             */
/*   Updated: 2017/06/27 13:11:34 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	a;

	a = 0;
	while (src[a] != '\0' && a < n)
	{
		dst[a] = src[a];
		a++;
	}
	while (a < n)
	{
		dst[a] = '\0';
		a++;
	}
	dst[a] = '\0';
	return (dst);
}
