/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 18:28:59 by qrosa             #+#    #+#             */
/*   Updated: 2017/06/27 13:10:21 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int n;

	if (s != NULL && f != NULL)
	{
		n = 0;
		while (s[n] != '\0')
		{
			f(n, &(s[n]));
			n++;
		}
	}
}
