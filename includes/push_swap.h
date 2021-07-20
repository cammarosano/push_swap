/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:28:55 by rcammaro          #+#    #+#             */
/*   Updated: 2021/04/15 19:05:43 by rcammaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_stacks
{
	int		*a;
	int		*b;
	int		len_a;
	int		len_b;
	t_list	*ops;
	int		*op_codes;
	t_list	*to_clear;
	int		mode_checker;
}				t_stacks;

enum	e_op_codes
{
	op_sa,
	op_sb,
	op_ss,
	op_pa,
	op_pb,
	op_ra,
	op_rb,
	op_rr,
	op_rra,
	op_rrb,
	op_rrr
};

enum	e_stack_id
{
	stack_a,
	stack_b
};

int		setup_stacks(t_stacks *s, int argc, char **argv, int *op_codes);
long	ft_strtol_mv_ptr(char **nptr);
int		parse_nbr(int *nbr, char *str);
int		check_duplicate(int *array, int new);
int		handle_single_str_arg(t_stacks *s, char *str);

void	exit_program(t_stacks *s, int exit_code);

void	sa(t_stacks *s);
void	sb(t_stacks *s);
void	ss(t_stacks *s);
void	pa(t_stacks *s);
void	pb(t_stacks *s);
void	ra(t_stacks *s);
void	rb(t_stacks *s);
void	rr(t_stacks *s);
void	rra(t_stacks *s);
void	rrb(t_stacks *s);
void	rrr(t_stacks *s);

int		is_sorted_a(int	*a, int top, int bot);

void	reverse_list(t_list **lst);
void	lst_rmv_elem(t_list **lst, t_list *elem);
void	add_op_2_list(t_stacks *s, int op);

int		optimize(int op, t_stacks *s);
int		opt_rotations(int new_op, t_stacks *s);
int		replace_2_rr(t_stacks *s, int match, int skip_1, int skip_2);
int		replace_2_rrr(t_stacks *s, int match, int skip_1, int skip_2);

void	sort_a(t_stacks *s, int part_len);
void	sort_b(t_stacks *s, int part_len);
int		select_best_algo(t_stacks *s, t_stacks *copy, int n);
void	stacks_dup(t_stacks *src, t_stacks *dst);
void	discard(t_stacks *s);
void	replace_ops_lst(t_stacks *s, t_stacks *s2);

void	insertion_sort_a(t_stacks *s, int size_a);
void	insertion_sort_b(t_stacks *s, int size_b);
int		calc_index(int origin, int offset, int array_len);
int		get_base_a(t_stacks *s, int size, int sorted_bottom, int x);
int		get_base_b(t_stacks *s, int size, int sorted_bottom, int x);

void	merge_sort_a(t_stacks *s, int part_len);
void	merge_sort_b(t_stacks *s, int part_len);
int		choose_split_size(t_stacks *s, int part_len, int stack_id);
void	move_to_top_a(t_stacks *s, int i_origin, int *i_bot);
void	move_to_top_b(t_stacks *s, int i_origin, int *i_bot);

int		get_median(int *array, int len);
void	quicksort_a(t_stacks *s, int size_a);
void	quicksort_b(t_stacks *s, int size_b);

void	hybrid_quick_ins_sort_a(t_stacks *s, int size_a);
void	insert_to_b(t_stacks *s, int incoming_nbr, int size_b);
void	hybrid_quick_ins_sort_b(t_stacks *s, int size_b);
void	insert_to_a(t_stacks *s, int incoming_nbr, int size_a);

void	sort_a_3(t_stacks *s);
void	sort_b_3(t_stacks *s);
void	sort_a_4(t_stacks *s);
void	sort_b_4(t_stacks *s);
void	sort_a_4_ultimate(t_stacks *s);
void	sort_a_4_1x(t_stacks *s, int top, int mid, int bot);
void	sort_a_4_2x(t_stacks *s, int top, int mid, int bot);
void	sort_a_4_3x(t_stacks *s, int top, int mid, int bot);
void	sort_a_4_4x(t_stacks *s, int top, int mid, int bot);
void	sort_b_4_ultimate(t_stacks *s);
void	sort_b_4_1x(t_stacks *s, int top, int mid, int bot);
void	sort_b_4_2x(t_stacks *s, int top, int mid, int bot);
void	sort_b_4_3x(t_stacks *s, int top, int mid, int bot);
void	sort_b_4_4x(t_stacks *s, int top, int mid, int bot);

#endif
