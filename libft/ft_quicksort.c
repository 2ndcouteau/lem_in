/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 13:41:03 by qrosa             #+#    #+#             */
/*   Updated: 2017/06/27 13:41:06 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	swap(void **array, int x, int y)
{
	void *tmp;

	tmp = array[x];
	array[x] = array[y];
	array[y] = tmp;
}

void		ft_quicksort(void **array, int start, int end, int (*get)(void *x))
{
	int i;
	int k;
	int pivot;

	i = start;
	k = end;
	if ((end - start) >= 1)
	{
		pivot = get(array[start]);
		while (k > i)
		{
			while (get(array[i]) <= pivot && i <= end && k > i)
				++i;
			while (get(array[k]) > pivot && k >= start && k >= i)
				--k;
			if (k > i)
				swap(array, i, k);
		}
		swap(array, start, k);
		ft_quicksort(array, start, k - 1, get);
		ft_quicksort(array, k + 1, end, get);
	}
}
