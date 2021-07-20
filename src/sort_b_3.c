/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:49:21 by rcammaro          #+#    #+#             */
/*   Updated: 2021/04/15 16:49:41 by rcammaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	case_312(t_stacks *s)
{
	if (s->len_b == 3)
	{
		rrb(s);
		sb(s);
		return ;
	}
	rb(s);
	sb(s);
	rrb(s);
}

static void	case_213(t_stacks *s)
{
	if (s->len_b == 3)
	{
		rrb(s);
		return ;
	}
	rb(s);
	sb(s);
	rrb(s);
	sb(s);
}

static void	case_132(t_stacks *s)
{
	if (s->len_b == 3)
	{
		rb(s);
		return ;
	}
	sb(s);
	case_312(s);
}

static void	case_123(t_stacks *s)
{
	sb(s);
	case_213(s);
}

void	sort_b_3(t_stacks *s)
{
	int	top;
	int	mid;
	int	bot;

	top = s->b[s->len_b - 1];
	mid = s->b[s->len_b - 2];
	bot = s->b[s->len_b - 3];
	if (top > mid && mid > bot)
		return ;
	if (mid > top && top > bot)
		sb(s);
	else if (top > bot && bot > mid)
		case_312(s);
	else if (bot > top && top > mid)
		case_213(s);
	else if (mid > bot && bot > top)
		case_132(s);
	else
		case_123(s);
}
