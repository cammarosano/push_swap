/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_4_ultimate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:52:47 by rcammaro          #+#    #+#             */
/*   Updated: 2021/04/15 16:53:35 by rcammaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	classify(int *b, int len)
{
	int	i;
	int	rank;
	int	top;

	top = b[len - 1];
	rank = 0;
	i = len - 2;
	while (i >= (len - 4))
	{
		if (top > b[i])
			rank++;
		i--;
	}
	return (rank);
}

// only for stack size of 4
void	sort_b_4_ultimate(t_stacks *s)
{
	int				second;
	int				third;
	int				fourth;
	int				rank;
	static	void	(*f[4])(t_stacks *s, int, int, int)
	= {sort_b_4_1x, sort_b_4_2x, sort_b_4_3x, sort_b_4_4x};

	rank = classify(s->b, s->len_b);
	second = s->b[s->len_b - 2];
	third = s->b[s->len_b - 3];
	fourth = s->b[s->len_b - 4];
	f[rank](s, second, third, fourth);
}
