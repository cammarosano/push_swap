/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_single_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 19:04:07 by rcammaro          #+#    #+#             */
/*   Updated: 2021/04/15 20:09:18 by rcammaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char **words)
{
	int	count;

	count = 0;
	while (*words++)
		count++;
	return (count);
}

static int	free_split_return(char **words)
{
	ft_free_split(words);
	return (0);
}

int	handle_single_str_arg(t_stacks *s, char *str)
{
	char	**words;
	int		i;

	s->a = NULL;
	s->b = NULL;
	words = ft_split(str, ' ');
	if (!words)
		exit_program(s, 1);
	s->len_a = count_words(words);
	s->len_b = 0;
	s->a = malloc(sizeof(int) * s->len_a);
	s->b = malloc(sizeof(int) * s->len_a);
	if (!s->a || !s->b)
		return (free_split_return(words));
	i = -1;
	while (++i < s->len_a)
	{
		if (!parse_nbr(&s->a[i], words[s->len_a - 1 - i]))
			return (free_split_return(words));
		if (!check_duplicate(s->a, i))
			return (free_split_return(words));
	}
	ft_free_split(words);
	return (1);
}
