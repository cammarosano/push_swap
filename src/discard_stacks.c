/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   discard_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:33:00 by rcammaro          #+#    #+#             */
/*   Updated: 2021/04/15 15:33:01 by rcammaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// removes last element of a list (do nothing if it is also the first)
static void	lst_remove_last(t_list *lst)
{
	if (!lst || !lst->next)
		return ;
	while (lst->next->next)
		lst = lst->next;
	free(lst->next);
	lst->next = NULL;
}

// free a, b, clear ops list, and remove last element of the list
void	discard(t_stacks *s)
{
	free(s->a);
	free(s->b);
	ft_lstclear(&s->ops, NULL);
	lst_remove_last(s->to_clear);
}

// clear s->ops list, make s->ops point to s2->ops, set this last one to NULL
void	replace_ops_lst(t_stacks *s, t_stacks *s2)
{
	ft_lstclear(&s->ops, NULL);
	s->ops = s2->ops;
	s2->ops = NULL;
}
