/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:46:31 by rcammaro          #+#    #+#             */
/*   Updated: 2021/04/15 16:46:32 by rcammaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_ins_sort_case(t_stacks *s)
{
	int	top;
	int	mid_top;
	int	mid_bot;
	int	bot;

	top = s->a[s->len_a - 1];
	mid_top = s->a[s->len_a - 2];
	mid_bot = s->a[s->len_a - 3];
	bot = s->a[s->len_a - 4];
	if (top < mid_bot && mid_bot < bot && bot < mid_top)
		return (1);
	if (top < mid_bot && mid_bot < mid_top && mid_top < bot)
		return (1);
	if (mid_top < mid_bot && mid_bot < top && top < bot)
		return (1);
	if (mid_top < mid_bot && mid_bot < bot && bot < top)
		return (1);
	if (mid_top < top && top < mid_bot && mid_bot < bot)
		return (1);
	return (0);
}

void	sort_a_4(t_stacks *s)
{
	if (s->len_a == 4)
		sort_a_4_ultimate(s);
	else
	{
		if (check_ins_sort_case(s))
			insertion_sort_a(s, 4);
		else
			merge_sort_a(s, 4);
	}
}
