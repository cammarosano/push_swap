/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hybrid_quick_ins_sort_b_2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:43:55 by rcammaro          #+#    #+#             */
/*   Updated: 2021/04/15 15:43:56 by rcammaro         ###   ########.fr       */
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
	while (past_op == op || past_op == op_rb || past_op == op_rrb
		|| past_op == op_sb)
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

static void	make_insertion(t_stacks *s, int n_ra, int n_rra)
{
	int	cost_ra;
	int	cost_rra;
	int	i;

	cost_ra = 2 * n_ra - 2 * count_op_list(s->ops, op_rra);
	cost_rra = 2 * n_rra + 1 - 2 * count_op_list(s->ops, op_ra);
	i = -1;
	if (cost_ra <= cost_rra)
	{
		while (++i < n_ra)
			ra(s);
		pa(s);
		while (n_ra--)
			rra(s);
	}
	else
	{
		while (++i < n_rra)
			rra(s);
		pa(s);
		while (n_rra-- + 1)
			ra(s);
	}
}

// find smallest elem in A that is bigger than incoming_nbr, move it to the top
// of A, push to A, and rotate back to sorted stack status
static void	general_case(t_stacks *s, int incoming_nbr)
{
	int	i;
	int	i_top;
	int	n_ra;
	int	n_rra;

	i_top = s->len_a - 1;
	i = i_top;
	while (s->a[i] < incoming_nbr)
		i--;
	n_ra = i_top - i;
	n_rra = s->len_a - n_ra;
	make_insertion(s, n_ra, n_rra);
}

static void	case_bigger_than_max(t_stacks *s, int size_a)
{
	int	i;

	if (size_a == s->len_a)
	{
		pa(s);
		ra(s);
		return ;
	}
	i = -1;
	while (++i < size_a)
		ra(s);
	pa(s);
	while (size_a--)
		rra(s);
}

void	insert_to_a(t_stacks *s, int incoming_nbr, int size_a)
{
	if (size_a == 0 || incoming_nbr < s->a[s->len_a - 1])
		pa(s);
	else if (size_a == 1 || incoming_nbr < s->a[s->len_a - 2])
	{
		pa(s);
		sa(s);
	}
	else if (incoming_nbr > s->a[s->len_a - size_a])
		case_bigger_than_max(s, size_a);
	else
		general_case(s, incoming_nbr);
}
