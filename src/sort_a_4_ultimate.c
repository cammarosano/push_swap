/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_4_ultimate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:43:00 by rcammaro          #+#    #+#             */
/*   Updated: 2021/04/15 16:44:19 by rcammaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	classify(int *a, int len)
{
	int	i;
	int	rank;
	int	top;

	top = a[len - 1];
	rank = 0;
	i = len - 2;
	while (i >= (len - 4))
	{
		if (top > a[i])
			rank++;
		i--;
	}
	return (rank);
}

// only for stack size of 4
void	sort_a_4_ultimate(t_stacks *s)
{
	int				second;
	int				third;
	int				fourth;
	int				rank;
	static	void	(*f[4])(t_stacks *s, int, int, int)
	= {sort_a_4_1x, sort_a_4_2x, sort_a_4_3x, sort_a_4_4x};

	rank = classify(s->a, s->len_a);
	second = s->a[s->len_a - 2];
	third = s->a[s->len_a - 3];
	fourth = s->a[s->len_a - 4];
	f[rank](s, second, third, fourth);
}
