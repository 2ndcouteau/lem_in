/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 19:44:24 by qrosa             #+#    #+#             */
/*   Updated: 2017/06/27 12:47:31 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	*ft_memalloc(size_t size)
{
	void	*freespace;

	freespace = NULL;
	if (size == 0)
		return (NULL);
	if (!(freespace = (void*)malloc(sizeof(char) * size)))
		return (NULL);
	ft_bzero(freespace, size);
	return (freespace);
}
