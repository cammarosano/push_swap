/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:53:04 by rcammaro          #+#    #+#             */
/*   Updated: 2021/04/15 15:53:29 by rcammaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_list(t_list **lst)
{
	t_list	*new_list;
	t_list	*tmp;

	new_list = NULL;
	while (*lst)
	{
		tmp = *lst;
		*lst = tmp->next;
		ft_lstadd_front(&new_list, tmp);
	}
	*lst = new_list;
}

void	add_op_2_list(t_stacks *s, int op)
{
	t_list	*elem;

	if (s->mode_checker || optimize(op, s))
		return ;
	elem = ft_lstnew(&s->op_codes[op]);
	if (!elem)
		exit_program(s, 1);
	ft_lstadd_front(&s->ops, elem);
}

// Removes node from list. Nothing is done about *content.
void	lst_rmv_elem(t_list **lst, t_list *elem)
{
	t_list	*ptr;

	if (*lst == elem)
	{
		*lst = elem->next;
		free(elem);
		return ;
	}
	ptr = *lst;
	while (ptr && ptr->next != elem)
		ptr = ptr->next;
	ptr->next = elem->next;
	free(elem);
}
