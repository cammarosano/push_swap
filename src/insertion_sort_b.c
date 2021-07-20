/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:47:46 by rcammaro          #+#    #+#             */
/*   Updated: 2021/04/15 16:15:18 by rcammaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// within the sorted subarray defined by bottom and size, 
// find index of the biggest element smallest than x
int	get_base_b(t_stacks *s, int size, int sorted_bottom, int x)
{
	int	sorted_top;
	int	i;

	sorted_top = calc_index(sorted_bottom, size - 1, s->len_b);
	i = sorted_top;
	while (size--)
	{
		if (s->b[i] < x)
			return (i);
		i = calc_index(i, -1, s->len_b);
	}
	return (i);
}

static void	make_insertion(t_stacks *s, int *sorted_bot, int size_sorted)
{
	int	base;
	int	unsorted_top;

	unsorted_top = calc_index(*sorted_bot, -1, s->len_b);
	move_to_top_b(s, unsorted_top, sorted_bot);
	pa(s);
	base = get_base_b(s, size_sorted, *sorted_bot, s->a[s->len_a - 1]);
	if (base == 0)
	{
		pb(s);
		rrb(s);
		sb(s);
		(*sorted_bot) = s->len_b - 2;
	}
	else
	{
		move_to_top_b(s, base, sorted_bot);
		pb(s);
	}
}

void	insertion_sort_b(t_stacks *s, int size_b)
{
	int	size_sorted;
	int	sorted_bot;
	int	unsorted_top;
	int	sorted_top;

	size_sorted = 1;
	sorted_bot = s->len_b - 1;
	while (size_sorted < size_b)
	{
		unsorted_top = calc_index(sorted_bot, -1, s->len_b);
		if (s->b[unsorted_top] > s->b[sorted_bot])
			make_insertion(s, &sorted_bot, size_sorted);
		else
			sorted_bot = unsorted_top;
		size_sorted++;
	}
	sorted_top = calc_index(sorted_bot, size_b - 1, s->len_b);
	move_to_top_b(s, sorted_top, &sorted_bot);
}
