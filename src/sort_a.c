/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:46:48 by rcammaro          #+#    #+#             */
/*   Updated: 2021/04/15 16:49:10 by rcammaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_a_2(t_stacks *s)
{
	int	top;
	int	bot;

	top = s->a[s->len_a - 1];
	bot = s->a[s->len_a - 2];
	if (top > bot)
		sa(s);
}

static void	sort_small_a(t_stacks *s, int part_len)
{
	if (part_len < 2)
		return ;
	if (part_len == 2)
		sort_a_2(s);
	else if (part_len == 3)
		sort_a_3(s);
	else
		sort_a_4(s);
}

// returns index of best copy, or -1 if s is best
int	select_best_algo(t_stacks *s, t_stacks *copy, int n)
{
	int	best;
	int	len_ops;
	int	len_ops_best;
	int	i;

	best = -1;
	len_ops_best = ft_lstsize(s->ops);
	i = 0;
	while (i < n)
	{
		len_ops = ft_lstsize(copy[i].ops);
		if (len_ops < len_ops_best)
		{
			best = i;
			len_ops_best = len_ops;
		}
		i++;
	}
	return (best);
}

void	sort_a(t_stacks *s, int part_len)
{
	t_stacks	copy[3];
	int			n_copies;
	int			best_algo;

	if (part_len < 5)
	{
		sort_small_a(s, part_len);
		return ;
	}
	stacks_dup(s, &copy[0]);
	stacks_dup(s, &copy[1]);
	n_copies = 2;
	insertion_sort_a(&copy[0], part_len);
	quicksort_a(&copy[1], part_len);
	if (part_len < 100)
	{
		stacks_dup(s, &copy[n_copies++]);
		hybrid_quick_ins_sort_a(&copy[2], part_len);
	}
	merge_sort_a(s, part_len);
	best_algo = select_best_algo(s, copy, n_copies);
	if (best_algo != -1)
		replace_ops_lst(s, &copy[best_algo]);
	while (--n_copies >= 0)
		discard(&copy[n_copies]);
}
