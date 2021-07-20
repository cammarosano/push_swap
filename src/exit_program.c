/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:36:19 by rcammaro          #+#    #+#             */
/*   Updated: 2021/04/15 15:36:20 by rcammaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	clear_stacks(void *arg)
{
	t_stacks	*s;

	s = arg;
	free(s->a);
	free(s->b);
	ft_lstclear(&s->ops, NULL);
}

// clears all the stacks in "s->to_clear" list. If there's no such list
// (checker mode), just clears s.
void	exit_program(t_stacks *s, int exit_code)
{
	t_list	*to_clear;

	to_clear = s->to_clear;
	if (!to_clear)
		clear_stacks(s);
	else
		ft_lstclear(&to_clear, clear_stacks);
	if (exit_code)
		ft_putendl_fd("Error", 2);
	exit(exit_code);
}
