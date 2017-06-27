/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_exists.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaosu <kaosu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 12:42:08 by kaosu             #+#    #+#             */
/*   Updated: 2017/06/27 13:27:35 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>

bool	ft_file_exists(const char *filename)
{
	FILE *file;

	if ((file = fopen(filename, "r")))
	{
		fclose(file);
		return (1);
	}
	return (0);
}
