/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:37:44 by rcammaro          #+#    #+#             */
/*   Updated: 2021/04/15 15:40:01 by rcammaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_count(int *array, int ref_value, int len)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < len)
	{
		if (ref_value > array[i])
			count++;
		i++;
	}
	return (count);
}

// Returns the the element that is bigger than len / 2 elements
// That means 3, in a 1 2 3 4 array.
int	get_median(int *array, int len)
{
	int	i;
	int	n_greater_than;
	int	too_small;
	int	too_big;

	too_small = INT_MIN;
	too_big = INT_MAX;
	i = 0;
	while (i < len - 1)
	{
		if (!(array[i] > too_big || array[i] < too_small))
		{
			n_greater_than = get_count(array, array[i], len);
			if (n_greater_than == len / 2)
				return (array[i]);
			if (n_greater_than < len / 2)
				too_small = array[i];
			else
				too_big = array[i];
		}
		i++;
	}
	return (array[i]);
}
