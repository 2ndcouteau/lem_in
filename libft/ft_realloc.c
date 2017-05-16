/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 17:40:37 by qrosa             #+#    #+#             */
/*   Updated: 2017/05/16 14:44:02 by yoko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memcpyy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if ((dest == 0) || (src == 0) || (n == 0))
		return (0);
	while (i < n && ((unsigned char*)src)[i] != '\0')
	{
		((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
		i++;
	}
	if (i < n)
	{
		while (i < n)
			((unsigned char*)dest)[i++] = 0;
	}
	return (dest);
}

void		*ft_realloc(void *ptr, size_t size)
{
	void	*result;

	if (size == 0)
	{
		if (ptr != NULL)
			free(ptr);
		ptr = NULL;
		return (ptr);
	}
	if (ptr == NULL)
	{
		if (!(result = malloc(size)))
			return (NULL);
		return (result);
	}
	if (!(result = malloc(size)))
		return (NULL);
	ft_memcpyy(result, ptr, size);
	free(ptr);
	ptr = NULL;
	return (result);
}
