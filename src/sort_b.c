/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 17:13:15 by rcammaro          #+#    #+#             */
/*   Updated: 2021/04/15 17:13:40 by rcammaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_b_2(t_stacks *s)
{
	int	top;
	int	bot;

	top = s->b[s->len_b - 1];
	bot = s->b[s->len_b - 2];
	if (top < bot)
		sb(s);
}

static void	sort_small_b(t_stacks *s, int part_len)
{
	if (part_len < 2)
		return ;
	if (part_len == 2)
		sort_b_2(s);
	else if (part_len == 3)
		sort_b_3(s);
	else
		sort_b_4(s);
}

void	sort_b(t_stacks *s, int part_len)
{
	t_stacks	copy[3];
	int			n_copies;
	int			best_algo;

	if (part_len < 5)
	{
		sort_small_b(s, part_len);
		return ;
	}
	stacks_dup(s, &copy[0]);
	stacks_dup(s, &copy[1]);
	n_copies = 2;
	insertion_sort_b(&copy[0], part_len);
	quicksort_b(&copy[1], part_len);
	if (part_len < 100)
	{
		stacks_dup(s, &copy[n_copies++]);
		hybrid_quick_ins_sort_b(&copy[2], part_len);
	}
	merge_sort_b(s, part_len);
	best_algo = select_best_algo(s, copy, n_copies);
	if (best_algo != -1)
		replace_ops_lst(s, &copy[best_algo]);
	while (--n_copies >= 0)
		discard(&copy[n_copies]);
}
