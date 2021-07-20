/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_rotations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:30:20 by rcammaro          #+#    #+#             */
/*   Updated: 2021/04/15 16:30:28 by rcammaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	del_rot_a(int new_op, t_stacks *s)
{
	int		past_op;
	t_list	*lst;

	lst = s->ops;
	if (!lst)
		return (0);
	past_op = *(int *)lst->content;
	while (past_op == op_sb || past_op == op_rb || past_op == op_rrb)
	{
		lst = lst->next;
		if (!lst)
			return (0);
		past_op = *(int *)lst->content;
	}
	if ((new_op == op_ra && past_op == op_rra)
		|| (new_op == op_rra && past_op == op_ra))
	{
		lst_rmv_elem(&s->ops, lst);
		return (1);
	}
	return (0);
}

int	del_rot_b(int new_op, t_stacks *s)
{
	int		past_op;
	t_list	*lst;

	lst = s->ops;
	if (!lst)
		return (0);
	past_op = *(int *)lst->content;
	while (past_op == op_sa || past_op == op_ra || past_op == op_rra)
	{
		lst = lst->next;
		if (!lst)
			return (0);
		past_op = *(int *)lst->content;
	}
	if ((new_op == op_rb && past_op == op_rrb)
		|| (new_op == op_rrb && past_op == op_rb))
	{
		lst_rmv_elem(&s->ops, lst);
		return (1);
	}
	return (0);
}

int	delete_opposite_rot(int op, t_stacks *s)
{
	if (op == op_ra || op == op_rra)
		return (del_rot_a(op, s));
	if (op == op_rb || op == op_rrb)
		return (del_rot_b(op, s));
	return (0);
}

int	opt_rotations(int new_op, t_stacks *s)
{
	if (delete_opposite_rot(new_op, s))
		return (1);
	if (new_op == op_ra)
		return (replace_2_rr(s, op_rb, op_sb, op_rrb));
	if (new_op == op_rb)
		return (replace_2_rr(s, op_ra, op_sa, op_rra));
	if (new_op == op_rra)
		return (replace_2_rrr(s, op_rrb, op_sb, op_rb));
	if (new_op == op_rrb)
		return (replace_2_rrr(s, op_rra, op_sa, op_ra));
	return (0);
}
