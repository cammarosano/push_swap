/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_4_2x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:41:49 by rcammaro          #+#    #+#             */
/*   Updated: 2021/04/15 16:42:05 by rcammaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	case_2314(t_stacks *s)
{
	ra(s);
	ra(s);
	sa(s);
	ra(s);
}

static void	case_2413(t_stacks *s)
{
	rra(s);
	sa(s);
	rra(s);
}

void	sort_a_4_2x(t_stacks *s, int top, int mid, int bot)
{	
	if ((bot < mid && bot < top) || (top < mid && mid < bot))
		insertion_sort_a(s, 4);
	else if (top < bot && bot < mid)
		merge_sort_a(s, 4);
	else if (mid < top && top < bot)
		case_2314(s);
	else
		case_2413(s);
}
