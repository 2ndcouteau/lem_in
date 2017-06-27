/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 18:07:42 by qrosa             #+#    #+#             */
/*   Updated: 2017/06/27 13:08:51 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strclr(char *s)
{
	int size;

	size = 0;
	if (s)
	{
		while (s[size])
		{
			s[size] = '\0';
			size++;
		}
	}
}
