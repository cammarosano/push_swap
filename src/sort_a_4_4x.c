/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_4_4x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:42:31 by rcammaro          #+#    #+#             */
/*   Updated: 2021/04/15 16:42:43 by rcammaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	case_4132(t_stacks *s)
{
	ra(s);
	ra(s);
	sa(s);
	rra(s);
}

static void	case_4231(t_stacks *s)
{
	rra(s);
	sa(s);
	ra(s);
}

static void	case_4312(t_stacks *s)
{
	sa(s);
	ra(s);
	ra(s);
}

static void	case_4321(t_stacks *s)
{
	sa(s);
	rra(s);
	rra(s);
	sa(s);
}

void	sort_a_4_4x(t_stacks *s, int top, int mid, int bot)
{
	if (top < mid && mid < bot)
		ra(s);
	else if (top < bot && bot < mid)
		case_4132(s);
	else if (mid < top && top < bot)
	{
		ra(s);
		sa(s);
	}
	else if (bot < top && top < mid)
		case_4231(s);
	else if (mid < bot && bot < top)
		case_4312(s);
	else
		case_4321(s);
}
