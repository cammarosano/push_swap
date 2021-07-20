/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_4_1x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:50:03 by rcammaro          #+#    #+#             */
/*   Updated: 2021/04/15 16:50:23 by rcammaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	case_1423(t_stacks *s)
{
	rb(s);
	rb(s);
	sb(s);
	rrb(s);
}

static void	case_1324(t_stacks *s)
{
	rrb(s);
	sb(s);
	rb(s);
}

static void	case_1243(t_stacks *s)
{
	sb(s);
	rb(s);
	rb(s);
}

static void	case_1234(t_stacks *s)
{
	sb(s);
	rrb(s);
	rrb(s);
	sb(s);
}

void	sort_b_4_1x(t_stacks *s, int top, int mid, int bot)
{
	if (top > mid && mid > bot)
		rb(s);
	else if (top > bot && bot > mid)
		case_1423(s);
	else if (mid > top && top > bot)
	{
		rb(s);
		sb(s);
	}
	else if (bot > top && top > mid)
		case_1324(s);
	else if (mid > bot && bot > top)
		case_1243(s);
	else
		case_1234(s);
}
