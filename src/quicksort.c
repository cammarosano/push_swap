/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:31:17 by rcammaro          #+#    #+#             */
/*   Updated: 2021/04/15 16:31:43 by rcammaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_to_b(t_stacks *s, int size_a, int median)
{
	int	top_nbr;
	int	n_rotated;
	int	n_pushed;
	int	need_2_recover;

	need_2_recover = (size_a < s->len_a);
	n_pushed = 0;
	n_rotated = 0;
	top_nbr = s->a[s->len_a - 1];
	while (n_pushed < size_a / 2)
	{
		if (top_nbr < median)
		{
			pb(s);
			n_pushed++;
		}
		else
		{
			ra(s);
			n_rotated++;
		}
		top_nbr = s->a[s->len_a - 1];
	}
	while (need_2_recover && n_rotated--)
		rra(s);
}

void	quicksort_a(t_stacks *s, int size_a)
{
	int	median;
	int	half_b;
	int	i_bot;

	i_bot = s->len_a - size_a;
	median = get_median(&s->a[i_bot], size_a);
	push_to_b(s, size_a, median);
	half_b = size_a / 2;
	sort_a(s, size_a - half_b);
	sort_b(s, half_b);
	while (half_b--)
		pa(s);
}

static void	push_to_a(t_stacks *s, int size_b, int median)
{
	int	top_nbr;
	int	n_rotated;
	int	n_pushed;
	int	need_2_recover;

	need_2_recover = (size_b < s->len_b);
	n_pushed = 0;
	n_rotated = 0;
	top_nbr = s->b[s->len_b - 1];
	while (n_pushed < size_b - size_b / 2)
	{
		if (top_nbr >= median)
		{
			pa(s);
			n_pushed++;
		}
		else
		{
			rb(s);
			n_rotated++;
		}
		top_nbr = s->b[s->len_b - 1];
	}
	while (need_2_recover && n_rotated--)
		rrb(s);
}

void	quicksort_b(t_stacks *s, int size_b)
{
	int	median;
	int	half_a;
	int	i_bot;

	i_bot = s->len_b - size_b;
	median = get_median(&s->b[i_bot], size_b);
	push_to_a(s, size_b, median);
	half_a = size_b - size_b / 2;
	sort_b(s, size_b / 2);
	sort_a(s, half_a);
	while (half_a--)
		pb(s);
}
