/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:36:19 by qrosa             #+#    #+#             */
/*   Updated: 2017/06/27 12:51:50 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			b;
	unsigned char	*dst1;
	unsigned char	*src1;

	b = 0;
	dst1 = (unsigned char*)dst;
	src1 = (unsigned char*)src;
	while (b < n)
	{
		dst1[b] = src1[b];
		b++;
	}
	return (dst);
}
