/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_function_djb2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoko <yoko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 01:51:18 by yoko              #+#    #+#             */
/*   Updated: 2017/06/27 10:13:39 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Hash method from http://www.cse.yorku.ca/~oz/hash.html
**	hash = ((hash << 5) + hash) + c; is the same as ==> hash = hash * 33 + c
*/

unsigned long	hash_djb2(unsigned char *str)
{
	unsigned long	hash;
	int				c;

	hash = 5381;
	c = *str;
	while (c != '\0')
	{
		hash = ((hash << 5) + hash) + c;
		c = *str++;
	}
	return (hash);
}
