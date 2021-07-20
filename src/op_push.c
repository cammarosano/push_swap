/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:27:51 by rcammaro          #+#    #+#             */
/*   Updated: 2021/04/15 16:28:08 by rcammaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stacks *s)
{
	if (s->len_b == 0)
		return ;
	s->a[s->len_a] = s->b[s->len_b - 1];
	(s->len_a)++;
	(s->len_b)--;
	add_op_2_list(s, op_pa);
}

void	pb(t_stacks *s)
{
	if (s->len_a == 0)
		return ;
	s->b[s->len_b] = s->a[s->len_a - 1];
	(s->len_b)++;
	(s->len_a)--;
	add_op_2_list(s, op_pb);
}
