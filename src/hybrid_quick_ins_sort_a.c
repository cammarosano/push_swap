/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hybrid_quick_ins_sort_a.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:42:42 by rcammaro          #+#    #+#             */
/*   Updated: 2021/04/15 15:43:42 by rcammaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_sort_to_b(t_stacks *s, int size_a, int median, int half_b)
{
	int	top_nbr;
	int	n_rotated;
	int	n_pushed;
	int	need_2_recover;

	need_2_recover = (size_a < s->len_a);
	n_pushed = 0;
	n_rotated = 0;
	top_nbr = s->a[s->len_a - 1];
	while (n_pushed < half_b)
	{
		if (top_nbr < median)
			insert_to_b(s, top_nbr, n_pushed++);
		else
		{
			ra(s);
			n_rotated++;
		}
		top_nbr = s->a[s->len_a - 1];
	}
	if (need_2_recover)
	{
		while (n_rotated--)
			rra(s);
	}
}

void	hybrid_quick_ins_sort_a(t_stacks *s, int size_a)
{
	int	median;
	int	half_b;
	int	i_bot;

	i_bot = s->len_a - size_a;
	median = get_median(&s->a[i_bot], size_a);
	half_b = size_a / 2;
	push_sort_to_b(s, size_a, median, half_b);
	sort_a(s, size_a - half_b);
	while (half_b--)
		pa(s);
}
