/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:53:41 by rcammaro          #+#    #+#             */
/*   Updated: 2021/04/15 15:55:38 by rcammaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Parse string into an int (op_code) and add it to list of ops
// if malloc error, return 0. return 1 otherwise.
// If op in not recognized set bad_op to 1;
static int	parse_op(t_stacks *s, char *line, int *bad_op)
{
	int			i;
	t_list		*new_elem;
	static char	*ops_text[11] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb",
									"rr", "rra", "rrb", "rrr"};

	i = 0;
	while (i < 11)
	{
		if (ft_strcmp(line, ops_text[i]) == 0)
		{
			new_elem = ft_lstnew(&s->op_codes[i]);
			if (!new_elem)
				return (0);
			ft_lstadd_front(&s->ops, new_elem);
			return (1);
		}
		i++;
	}
	*bad_op = 1;
	return (1);
}

// read lines from stdin and parse instructions. An instruction not
// followed by a '\n' will be ignored. An empty line will be consided a
// bad instruction.
static void	read_instructions(t_stacks *s)
{
	char	*line;
	int		ret;
	int		bad_op;

	bad_op = 0;
	ret = get_next_line(0, &line);
	while (ret == 1)
	{
		ret = parse_op(s, line, &bad_op);
		free(line);
		if (!ret)
			exit_program(s, 1);
		ret = get_next_line(0, &line);
	}
	if (ret == -1)
		exit_program(s, 1);
	free(line);
	if (bad_op)
		exit_program(s, 1);
}

static void	do_ops(t_stacks *s)
{
	t_list			*lst;
	int				op;
	static	void	(*f[11])(t_stacks *s) = {sa, sb, ss, pa, pb, ra, rb, rr,
		rra, rrb, rrr};

	reverse_list(&s->ops);
	lst = s->ops;
	while (lst)
	{
		op = *(int *)lst->content;
		f[op](s);
		lst = lst->next;
	}
}

// main for checker program 
int	main(int argc, char **argv)
{
	int			op_codes[11];
	t_stacks	s;

	if (argc < 2)
		return (1);
	s.mode_checker = 1;
	if (!setup_stacks(&s, argc, argv, op_codes))
		exit_program(&s, 1);
	read_instructions(&s);
	do_ops(&s);
	if (s.len_b == 0 && is_sorted_a(s.a, s.len_a - 1, 0))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	exit_program(&s, 0);
}
