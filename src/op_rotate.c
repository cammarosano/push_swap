/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:28:49 by rcammaro          #+#    #+#             */
/*   Updated: 2021/04/15 16:28:56 by rcammaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(int *stack, int len)
{
	int	tmp;
	int	i;

	if (len < 2)
		return ;
	i = len - 1;
	tmp = stack[i];
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = tmp;
}

void	ra(t_stacks *s)
{
	rotate(s->a, s->len_a);
	add_op_2_list(s, op_ra);
}

void	rb(t_stacks *s)
{
	rotate(s->b, s->len_b);
	add_op_2_list(s, op_rb);
}

void	rr(t_stacks *s)
{
	rotate(s->a, s->len_a);
	rotate(s->b, s->len_b);
	add_op_2_list(s, op_rr);
}
