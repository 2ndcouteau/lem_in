/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 19:20:26 by qrosa             #+#    #+#             */
/*   Updated: 2017/05/21 06:39:43 by yoko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char const *str, size_t pos, size_t len_words)
{
	char	*line;
	size_t	len;

	len = 0;
	if (!(line = (char*)ft_memalloc(len_words + 1)))
		return (NULL);
	while (len < len_words)
	{
		line[len] = str[pos + len];
		len++;
	}
	line[len] = '\0';
	return (line);
}
