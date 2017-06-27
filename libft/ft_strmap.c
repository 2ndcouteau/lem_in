/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 18:51:21 by qrosa             #+#    #+#             */
/*   Updated: 2017/06/27 13:37:21 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*d;
	int		n;

	if (s != NULL && f != NULL)
	{
		d = ft_strdup(s);
		n = 0;
		while (d[n] != '\0')
		{
			d[n] = f(d[n]);
			n++;
		}
		return (d);
	}
	else
		return (NULL);
}
