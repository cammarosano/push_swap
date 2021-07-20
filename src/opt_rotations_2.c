/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_rotations_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:29:55 by rcammaro          #+#    #+#             */
/*   Updated: 2021/04/15 16:29:56 by rcammaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	replace_2_rr(t_stacks *s, int match, int skip_1, int skip_2)
{
	int		past_op;
	t_list	*lst;

	lst = s->ops;
	if (!lst)
		return (0);
	past_op = *(int *)lst->content;
	while (past_op == skip_1 || past_op == skip_2)
	{
		lst = lst->next;
		if (!lst)
			return (0);
		past_op = *(int *)lst->content;
	}
	if (past_op == match)
	{
		lst->content = &s->op_codes[op_rr];
		return (1);
	}
	return (0);
}

int	replace_2_rrr(t_stacks *s, int match, int skip_1, int skip_2)
{
	int		past_op;
	t_list	*lst;

	lst = s->ops;
	if (!lst)
		return (0);
	past_op = *(int *)lst->content;
	while (past_op == skip_1 || past_op == skip_2)
	{
		lst = lst->next;
		if (!lst)
			return (0);
		past_op = *(int *)lst->content;
	}
	if (past_op == match)
	{
		lst->content = &s->op_codes[op_rrr];
		return (1);
	}
	return (0);
}
