/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:56:07 by rcammaro          #+#    #+#             */
/*   Updated: 2021/04/15 15:56:43 by rcammaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	setup_to_clear_list(t_stacks *s)
{
	s->to_clear = ft_lstnew(s);
	if (!s->to_clear)
		exit_program(s, 1);
}

static void	print_ops(t_list **lst)
{
	int			op;
	t_list		*ptr;
	static char	*ops_text[11] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb",
									"rr", "rra", "rrb", "rrr"};

	reverse_list(lst);
	ptr = *lst;
	while (ptr)
	{
		op = *(int *)ptr->content;
		ft_putendl_fd(ops_text[op], 1);
		ptr = ptr->next;
	}
}

// main for push_swap program
int	main(int argc, char **argv)
{
	int			op_codes[11];
	t_stacks	s;

	if (argc < 2)
		return (1);
	s.mode_checker = 0;
	if (!setup_stacks(&s, argc, argv, op_codes))
		exit_program(&s, 1);
	setup_to_clear_list(&s);
	sort_a(&s, s.len_a);
	print_ops(&s.ops);
	exit_program(&s, 0);
}
