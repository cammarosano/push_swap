/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_4_4x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:52:36 by rcammaro          #+#    #+#             */
/*   Updated: 2021/04/15 16:52:37 by rcammaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	case_4123(t_stacks *s)
{
	pa(s);
	sb(s);
	rrb(s);
	pb(s);
}

static void	case_4132(t_stacks *s)
{
	sb(s);
	rb(s);
}

static void	case_4312(t_stacks *s)
{
	pa(s);
	rrb(s);
	sb(s);
	pb(s);
}

static void	case_4231(t_stacks *s)
{
	rrb(s);
	sb(s);
}

void	sort_b_4_4x(t_stacks *s, int top, int mid, int bot)
{
	if (top > mid && mid > bot)
		return ;
	if (mid > top && top > bot)
		insertion_sort_b(s, 4);
	else if (mid > bot && bot > top)
		case_4132(s);
	else if (bot > mid && mid > top)
		case_4123(s);
	else if (top > bot && bot > mid)
		case_4312(s);
	else
		case_4231(s);
}
