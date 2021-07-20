/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:30:54 by rcammaro          #+#    #+#             */
/*   Updated: 2021/04/15 16:30:55 by rcammaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	replace_2_ss(t_stacks *s, int match, int skip_1, int skip_2)
{
	int		past_op;
	t_list	*lst;

	lst = s->ops;
	if (!lst)
		return (0);
	past_op = *(int *)lst->content;
	while (past_op == skip_1 || past_op == skip_2)
	{
		lst = lst->next;
		if (!lst)
			return (0);
		past_op = *(int *)lst->content;
	}
	if (past_op == match)
	{
		lst->content = &s->op_codes[op_ss];
		return (1);
	}
	return (0);
}

static int	opt_swap(int new_op, t_stacks *s)
{
	if (new_op == op_sa)
		return (replace_2_ss(s, op_sb, op_rb, op_rrb));
	if (new_op == op_sb)
		return (replace_2_ss(s, op_sa, op_ra, op_rra));
	return (0);
}

static int	opt_push(int new_op, t_stacks *s)
{
	int		last_op;
	t_list	*lst;

	lst = s->ops;
	if (!lst)
		return (0);
	last_op = *(int *)lst->content;
	if ((new_op == op_pa && last_op == op_pb)
		|| (new_op == op_pb && last_op == op_pa))
	{
		lst_rmv_elem(&s->ops, lst);
		return (1);
	}
	return (0);
}

int	optimize(int op, t_stacks *s)
{
	if (op == op_pa || op == op_pb)
		return (opt_push(op, s));
	if (op == op_sa || op == op_sb)
		return (opt_swap(op, s));
	if (op >= op_ra && op <= op_rrr)
		return (opt_rotations(op, s));
	return (0);
}
