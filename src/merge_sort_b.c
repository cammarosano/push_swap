/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:24:02 by rcammaro          #+#    #+#             */
/*   Updated: 2021/04/15 16:25:16 by rcammaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_top_b(t_stacks *s, int i_origin, int *i_bot)
{
	int	i_top;
	int	rb_n;
	int	rrb_n;

	i_top = s->len_b - 1;
	rb_n = i_top - i_origin;
	rrb_n = i_origin + 1;
	if (rb_n <= rrb_n)
	{
		while (rb_n--)
		{
			rb(s);
			*i_bot = (*i_bot + 1) % s->len_b;
		}
		return ;
	}
	while (rrb_n--)
	{
		rrb(s);
		*i_bot = (*i_bot - 1 + s->len_b) % s->len_b;
	}
}

void	merge_to_b(t_stacks *s, int size_b, int size_a)
{
	int	min_b;
	int	i_base;
	int	i_bot;
	int	top_a;

	i_bot = s->len_b - size_b;
	min_b = s->b[i_bot];
	top_a = s->a[s->len_a - 1];
	if (top_a < min_b)
	{
		if (size_b < s->len_b)
			move_to_top_b(s, i_bot - 1, &i_bot);
		pb(s);
		size_b++;
		size_a--;
		i_bot = s->len_b - 1;
	}
	while (size_a--)
	{
		i_base = get_base_b(s, size_b, i_bot, s->a[s->len_a - 1]);
		move_to_top_b(s, i_base, &i_bot);
		pb(s);
		size_b++;
	}
	move_to_top_b(s, (i_bot + size_b - 1) % s->len_b, &i_bot);
}

void	merge_sort_b(t_stacks *s, int part_len)
{
	int	half_a;
	int	half_b;
	int	i;

	half_a = choose_split_size(s, part_len, stack_b);
	if (half_a == 0)
		return ;
	half_b = part_len - half_a;
	i = -1;
	while (++i < half_a)
		pa(s);
	sort_a(s, half_a);
	sort_b(s, half_b);
	merge_to_b(s, half_b, half_a);
}
