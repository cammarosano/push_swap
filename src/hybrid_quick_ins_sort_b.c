/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hybrid_quick_ins_sort_b.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:44:37 by rcammaro          #+#    #+#             */
/*   Updated: 2021/04/15 15:44:38 by rcammaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_sort_to_a(t_stacks *s, int size_b, int median, int half_a)
{
	int	top_nbr;
	int	n_rotated;
	int	n_pushed;
	int	need_2_recover;

	need_2_recover = (size_b < s->len_b);
	n_pushed = 0;
	n_rotated = 0;
	top_nbr = s->b[s->len_b - 1];
	while (n_pushed < half_a)
	{
		if (top_nbr >= median)
			insert_to_a(s, top_nbr, n_pushed++);
		else
		{
			rb(s);
			n_rotated++;
		}
		top_nbr = s->b[s->len_b - 1];
	}
	if (need_2_recover)
	{
		while (n_rotated--)
			rrb(s);
	}
}

void	hybrid_quick_ins_sort_b(t_stacks *s, int size_b)
{
	int	median;
	int	half_a;
	int	i_bot;

	i_bot = s->len_b - size_b;
	median = get_median(&s->b[i_bot], size_b);
	half_a = size_b - size_b / 2;
	push_sort_to_a(s, size_b, median, half_a);
	sort_b(s, size_b / 2);
	while (half_a--)
		pb(s);
}
