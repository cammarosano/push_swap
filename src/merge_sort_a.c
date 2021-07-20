/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:14:35 by rcammaro          #+#    #+#             */
/*   Updated: 2021/04/15 16:23:50 by rcammaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_top_a(t_stacks *s, int i_origin, int *i_bot)
{
	int	i_top;
	int	ra_n;
	int	rra_n;

	i_top = s->len_a - 1;
	ra_n = i_top - i_origin;
	rra_n = i_origin + 1;
	if (ra_n <= rra_n)
	{
		while (ra_n--)
		{
			ra(s);
			*i_bot = (*i_bot + 1) % s->len_a;
		}
		return ;
	}
	while (rra_n--)
	{
		rra(s);
		*i_bot = (*i_bot - 1 + s->len_a) % s->len_a;
	}
}

void	merge_to_a(t_stacks *s, int size_a, int size_b)
{
	int	max_a;
	int	i_base;
	int	i_bot;
	int	top_b;

	i_bot = s->len_a - size_a;
	max_a = s->a[i_bot];
	top_b = s->b[s->len_b - 1];
	if (top_b > max_a)
	{
		if (size_a < s->len_a)
			move_to_top_a(s, i_bot - 1, &i_bot);
		pa(s);
		size_a++;
		size_b--;
		i_bot = s->len_a - 1;
	}
	while (size_b--)
	{
		i_base = get_base_a(s, size_a, i_bot, s->b[s->len_b - 1]);
		move_to_top_a(s, i_base, &i_bot);
		pa(s);
		size_a++;
	}
	move_to_top_a(s, (i_bot + size_a - 1) % s->len_a, &i_bot);
}

void	merge_sort_a(t_stacks *s, int part_len)
{
	int	half_a;
	int	half_b;
	int	i;

	half_b = choose_split_size(s, part_len, stack_a);
	if (half_b == 0)
		return ;
	half_a = part_len - half_b;
	i = -1;
	while (++i < half_b)
		pb(s);
	sort_b(s, half_b);
	sort_a(s, half_a);
	merge_to_a(s, half_a, half_b);
}
