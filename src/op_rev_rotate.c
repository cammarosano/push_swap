/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:28:20 by rcammaro          #+#    #+#             */
/*   Updated: 2021/04/15 16:28:28 by rcammaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(int *stack, int len)
{
	int	tmp;
	int	i;

	if (len < 2)
		return ;
	tmp = stack[0];
	i = 0;
	while (i < len - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[len - 1] = tmp;
}

void	rra(t_stacks *s)
{
	reverse_rotate(s->a, s->len_a);
	add_op_2_list(s, op_rra);
}

void	rrb(t_stacks *s)
{
	reverse_rotate(s->b, s->len_b);
	add_op_2_list(s, op_rrb);
}

void	rrr(t_stacks *s)
{
	reverse_rotate(s->a, s->len_a);
	reverse_rotate(s->b, s->len_b);
	add_op_2_list(s, op_rrr);
}
