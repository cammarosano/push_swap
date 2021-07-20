/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_4_2x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:50:36 by rcammaro          #+#    #+#             */
/*   Updated: 2021/04/15 16:50:37 by rcammaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	case_2143(t_stacks *s)
{
	rb(s);
	rb(s);
}

static void	case_2413(t_stacks *s)
{
	sb(s);
	rrb(s);
	sb(s);
}

static void	case_2134(t_stacks *s)
{
	rb(s);
	rb(s);
	sb(s);
}

static void	case_2341(t_stacks *s)
{
	rrb(s);
	sb(s);
	rb(s);
	rb(s);
	sb(s);
}

void	sort_b_4_2x(t_stacks *s, int top, int mid, int bot)
{
	if ((top > mid && mid > bot) || (bot > top && top > mid))
		insertion_sort_b(s, 4);
	else if (mid > bot && bot > top)
		case_2143(s);
	else if (top > bot && bot > mid)
		case_2413(s);
	else if (bot > mid && mid > top)
		case_2134(s);
	else
		case_2341(s);
}
