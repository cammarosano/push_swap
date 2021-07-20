/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_4_1x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:40:14 by rcammaro          #+#    #+#             */
/*   Updated: 2021/04/15 16:40:44 by rcammaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	case_1432(t_stacks *s)
{
	pb(s);
	sa(s);
	rra(s);
	pa(s);
}

static void	case_1423(t_stacks *s)
{
	sa(s);
	ra(s);
}

static void	case_1243(t_stacks *s)
{
	pb(s);
	rra(s);
	sa(s);
	pa(s);
}

static void	case_1324(t_stacks *s)
{
	rra(s);
	sa(s);
}

void	sort_a_4_1x(t_stacks *s, int top, int mid, int bot)
{
	if (top < mid && mid < bot)
		return ;
	if (mid < top && top < bot)
		insertion_sort_a(s, 4);
	else if (mid < bot && bot < top)
		case_1423(s);
	else if (bot < mid && mid < top)
		case_1432(s);
	else if (top < bot && bot < mid)
		case_1243(s);
	else
		case_1324(s);
}
