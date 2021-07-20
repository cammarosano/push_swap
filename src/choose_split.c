/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:32:39 by rcammaro          #+#    #+#             */
/*   Updated: 2021/04/15 15:32:40 by rcammaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted_b(int *b, int top, int bot)
{
	int	i;

	i = top;
	while (i > bot)
	{
		if (b[i] < b[i - 1])
			return (0);
		i--;
	}
	return (1);
}

// search in the upper half of part_len for the beggining of a sorted list
// if not found, return part_len / 2
int	choose_split_size(t_stacks *s, int part_len, int stack_id)
{
	int	i;
	int	i_bot;
	int	i_top;
	int	i_half;
	int	stack_len;

	stack_len = s->len_a;
	if (stack_id == stack_b)
		stack_len = s->len_b;
	i_half = stack_len - part_len / 2;
	i_bot = stack_len - part_len;
	i_top = stack_len - 1;
	i = i_top;
	while (i >= i_half)
	{
		if (stack_id == stack_a && is_sorted_a(s->a, i, i_bot))
			return (i_top - i);
		if (stack_id == stack_b && is_sorted_b(s->b, i, i_bot))
			return (i_top - i);
		i--;
	}
	return (part_len / 2);
}
