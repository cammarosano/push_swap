/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:29:21 by rcammaro          #+#    #+#             */
/*   Updated: 2021/04/15 16:29:22 by rcammaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *stack, int len)
{
	int	tmp;

	if (len < 2)
		return ;
	tmp = stack[len - 1];
	stack[len - 1] = stack[len - 2];
	stack[len - 2] = tmp;
}

void	sa(t_stacks *s)
{
	swap(s->a, s->len_a);
	add_op_2_list(s, op_sa);
}

void	sb(t_stacks *s)
{
	swap(s->b, s->len_b);
	add_op_2_list(s, op_sb);
}

void	ss(t_stacks *s)
{
	swap(s->a, s->len_a);
	swap(s->b, s->len_b);
	add_op_2_list(s, op_ss);
}
