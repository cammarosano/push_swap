/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:49:18 by rcammaro          #+#    #+#             */
/*   Updated: 2021/04/15 15:52:17 by rcammaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Checks whether the segment of array a defined by indexes 
// top and bot (inclusive) is sorted in ascending order from top to bot.
int	is_sorted_a(int	*a, int top, int bot)
{
	int	i;

	i = top;
	while (i > bot)
	{
		if (a[i] > a[i - 1])
			return (0);
		i--;
	}
	return (1);
}
