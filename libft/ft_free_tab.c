/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 22:40:14 by qrosa             #+#    #+#             */
/*   Updated: 2017/06/27 12:35:45 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**ft_free_tab(char **mytab)
{
	int	i;

	i = 0;
	if (mytab != NULL)
	{
		while (mytab[i] != NULL)
		{
			free(mytab[i]);
			mytab[i] = NULL;
			i++;
		}
		free(mytab);
	}
	return (NULL);
}
