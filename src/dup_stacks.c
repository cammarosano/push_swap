/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_stacks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:35:49 by rcammaro          #+#    #+#             */
/*   Updated: 2021/04/15 15:35:50 by rcammaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	*copy_reference(void *content)
{
	return (content);
}

// returns 1 if list is successfully duplicated of if src list is empty.
// returns 0 if error.
int	dup_ops_list(t_list *src, t_list **dst)
{
	if (src == NULL)
		return (1);
	*dst = ft_lstmap(src, copy_reference, NULL);
	if (!*dst)
		return (0);
	return (1);
}

// copy contents of src to dst, add dst to end of to_clear list
void	stacks_dup(t_stacks *src, t_stacks *dst)
{
	int		n;
	t_list	*node;

	node = ft_lstnew(dst);
	if (!node)
		exit_program(src, 1);
	ft_lstadd_back(&src->to_clear, node);
	dst->ops = NULL;
	n = src->len_a + src->len_b;
	dst->a = malloc(sizeof(int) * n);
	dst->b = malloc(sizeof(int) * n);
	if (!dst->a || !dst->b)
		exit_program(src, 1);
	ft_memcpy(dst->a, src->a, sizeof(int) * src->len_a);
	ft_memcpy(dst->b, src->b, sizeof(int) * src->len_b);
	dst->len_a = src->len_a;
	dst->len_b = src->len_b;
	dst->op_codes = src->op_codes;
	if (!dup_ops_list(src->ops, &dst->ops))
		exit_program(src, 1);
	dst->to_clear = src->to_clear;
	dst->mode_checker = 0;
}
