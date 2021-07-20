/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:39:21 by rcammaro          #+#    #+#             */
/*   Updated: 2021/04/15 16:39:53 by rcammaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	case_132(t_stacks *s)
{
	if (s->len_a == 3)
	{
		rra(s);
		sa(s);
		return ;
	}
	ra(s);
	sa(s);
	rra(s);
}

static void	case_231(t_stacks *s)
{
	if (s->len_a == 3)
	{
		rra(s);
		return ;
	}
	ra(s);
	sa(s);
	rra(s);
	sa(s);
}

static void	case_312(t_stacks *s)
{
	if (s->len_a == 3)
	{
		ra(s);
		return ;
	}
	sa(s);
	case_132(s);
}

static void	case_321(t_stacks *s)
{
	sa(s);
	case_231(s);
}

void	sort_a_3(t_stacks *s)
{
	int	top;
	int	mid;
	int	bot;

	top = s->a[s->len_a - 1];
	mid = s->a[s->len_a - 2];
	bot = s->a[s->len_a - 3];
	if (top < mid && mid < bot)
		return ;
	if (mid < top && top < bot)
		sa(s);
	else if (top < bot && bot < mid)
		case_132(s);
	else if (bot < top && top < mid)
		case_231(s);
	else if (mid < bot && bot < top)
		case_312(s);
	else
		case_321(s);
}
