/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:34:30 by rcammaro          #+#    #+#             */
/*   Updated: 2021/04/15 19:02:11 by rcammaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	setup_op_codes(int *ops, t_stacks *s)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		ops[i] = i;
		i++;
	}
	s->op_codes = ops;
}

// Checks if empty string, parses string into a long, checks if within limits
// of int, check if no chars after the number, and checks if there was a digit
// in the string (avoid parsing 0 out of + or -).
int	parse_nbr(int *nbr, char *str)
{
	long	parsed_nbr;

	if (!*str)
		return (0);
	parsed_nbr = ft_strtol_mv_ptr(&str);
	if (parsed_nbr > INT_MAX || parsed_nbr < INT_MIN)
		return (0);
	if (*str != '\0')
		return (0);
	if (!ft_isdigit(*--str))
		return (0);
	*nbr = (int)parsed_nbr;
	return (1);
}

int	check_duplicate(int *array, int new)
{
	int	i;

	i = 0;
	while (i < new)
	{
		if (array[i] == array[new])
			return (0);
		i++;
	}
	return (1);
}

// Allocate memory to stacks A and B, initialize lists (ops, to_clear) to NULL,
// parse arguments and setup the op_codes.
// Returns 0 if error (allocated memory must still be cleared by the caller).
int	setup_stacks(t_stacks *s, int argc, char **argv, int *op_codes)
{
	int	i;

	s->ops = NULL;
	s->to_clear = NULL;
	setup_op_codes(op_codes, s);
	if (argc == 2)
		return (handle_single_str_arg(s, argv[1]));
	s->len_a = argc - 1;
	s->len_b = 0;
	s->a = malloc(sizeof(int) * s->len_a);
	s->b = malloc(sizeof(int) * s->len_a);
	if (!s->a || !s->b)
		return (0);
	i = 0;
	while (i < s->len_a)
	{
		if (!parse_nbr(&s->a[i], argv[argc - 1 - i]))
			return (0);
		if (!check_duplicate(s->a, i))
			return (0);
		i++;
	}
	return (1);
}
