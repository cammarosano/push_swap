/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hybrid_quick_ins_sort_a_2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:40:50 by rcammaro          #+#    #+#             */
/*   Updated: 2021/04/15 15:42:13 by rcammaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_op_list(t_list *lst, int op)
{
	int	past_op;
	int	count;

	count = 0;
	if (!lst)
		return (count);
	past_op = *(int *)lst->content;
	while (past_op == op || past_op == op_ra || past_op == op_rra
		|| past_op == op_sa)
	{
		if (past_op == op)
			count++;
		lst = lst->next;
		if (!lst)
			return (count);
		past_op = *(int *)lst->content;
	}
	return (count);
}

static void	make_insertion(t_stacks *s, int n_rb, int n_rrb)
{
	int	cost_rb;
	int	cost_rrb;
	int	i;

	cost_rb = 2 * n_rb - 2 * count_op_list(s->ops, op_rrb);
	cost_rrb = 2 * n_rrb + 1 - 2 * count_op_list(s->ops, op_rb);
	i = -1;
	if (cost_rb <= cost_rrb)
	{
		while (++i < n_rb)
			rb(s);
		pb(s);
		while (n_rb--)
			rrb(s);
	}
	else
	{
		while (++i < n_rrb)
			rrb(s);
		pb(s);
		while (n_rrb-- + 1)
			rb(s);
	}
}

// Find biggest elem in B that is smaller than incoming_nbr, move it to the top
// of B, push to B, and rotate back to sorted stack status
static void	general_case(t_stacks *s, int incoming_nbr)
{
	int	i;
	int	i_top;
	int	n_rb;
	int	n_rrb;

	i_top = s->len_b - 1;
	i = i_top;
	while (s->b[i] > incoming_nbr)
		i--;
	n_rb = i_top - i;
	n_rrb = s->len_b - n_rb;
	make_insertion(s, n_rb, n_rrb);
}

static void	case_smaller_than_min(t_stacks *s, int size_b)
{
	int	i;

	if (size_b == s->len_b)
	{
		pb(s);
		rb(s);
		return ;
	}
	i = -1;
	while (++i < size_b)
		rb(s);
	pb(s);
	i = -1;
	while (++i < size_b)
		rrb(s);
}

void	insert_to_b(t_stacks *s, int incoming_nbr, int size_b)
{
	if (size_b == 0)
		pb(s);
	else if (incoming_nbr > s->b[s->len_b - 1])
		pb(s);
	else if (size_b == 1 || incoming_nbr > s->b[s->len_b - 2])
	{
		pb(s);
		sb(s);
	}
	else if (incoming_nbr < s->b[s->len_b - size_b])
		case_smaller_than_min(s, size_b);
	else
		general_case(s, incoming_nbr);
}
