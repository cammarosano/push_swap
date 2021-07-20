/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_4_3x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:42:13 by rcammaro          #+#    #+#             */
/*   Updated: 2021/04/15 16:42:21 by rcammaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	case_3412(t_stacks *s)
{
	ra(s);
	ra(s);
}

static void	case_3142(t_stacks *s)
{
	sa(s);
	rra(s);
	sa(s);
}

static void	case_3421(t_stacks *s)
{
	ra(s);
	ra(s);
	sa(s);
}

static void	case_3214(t_stacks *s)
{
	rra(s);
	sa(s);
	ra(s);
	ra(s);
	sa(s);
}

void	sort_a_4_3x(t_stacks *s, int top, int mid, int bot)
{
	if ((top < mid && mid < bot) || (bot < top && top < mid))
		insertion_sort_a(s, 4);
	else if (mid < bot && bot < top)
		case_3412(s);
	else if (top < bot && bot < mid)
		case_3142(s);
	else if (bot < mid && mid < top)
		case_3421(s);
	else
		case_3214(s);
}
