/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:46:02 by rcammaro          #+#    #+#             */
/*   Updated: 2021/04/15 16:10:57 by rcammaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_index(int origin, int offset, int array_len)
{
	return ((origin + offset + array_len) % array_len);
}

// within the sorted subarray defined by bottom and size, 
// find index of the smallest element bigger than x
int	get_base_a(t_stacks *s, int size, int sorted_bottom, int x)
{
	int	sorted_top;
	int	i;

	sorted_top = calc_index(sorted_bottom, size - 1, s->len_a);
	i = sorted_top;
	while (size--)
	{
		if (s->a[i] > x)
			return (i);
		i = calc_index(i, -1, s->len_a);
	}
	return (i);
}

static void	make_insertion(t_stacks *s, int *sorted_bot, int size_sorted)
{
	int	base;
	int	unsorted_top;

	unsorted_top = calc_index(*sorted_bot, -1, s->len_a);
	move_to_top_a(s, unsorted_top, sorted_bot);
	pb(s);
	base = get_base_a(s, size_sorted, *sorted_bot, s->b[s->len_b - 1]);
	if (base == 0)
	{
		pa(s);
		rra(s);
		sa(s);
		(*sorted_bot) = s->len_a - 2;
	}
	else
	{
		move_to_top_a(s, base, sorted_bot);
		pa(s);
	}
}

void	insertion_sort_a(t_stacks *s, int size_a)
{
	int	size_sorted;
	int	sorted_bot;
	int	unsorted_top;
	int	sorted_top;

	size_sorted = 1;
	sorted_bot = s->len_a - 1;
	while (size_sorted < size_a)
	{
		unsorted_top = calc_index(sorted_bot, -1, s->len_a);
		if (s->a[unsorted_top] < s->a[sorted_bot])
			make_insertion(s, &sorted_bot, size_sorted);
		else
			sorted_bot = unsorted_top;
		size_sorted++;
	}
	sorted_top = calc_index(sorted_bot, size_a - 1, s->len_a);
	move_to_top_a(s, sorted_top, &sorted_bot);
}
