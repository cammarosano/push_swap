/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_4_3x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:51:29 by rcammaro          #+#    #+#             */
/*   Updated: 2021/04/15 16:51:49 by rcammaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	case_3241(t_stacks *s)
{
	rb(s);
	rb(s);
	sb(s);
	rb(s);
}

static void	case_3142(t_stacks *s)
{
	rrb(s);
	sb(s);
	rrb(s);
}

void	sort_b_4_3x(t_stacks *s, int top, int mid, int bot)
{	
	if ((bot > mid && bot > top) || (top > mid && mid > bot))
		insertion_sort_b(s, 4);
	else if (top > bot && bot > mid)
		merge_sort_b(s, 4);
	else if (mid > top && top > bot)
		case_3241(s);
	else
		case_3142(s);
}
