# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/15 17:32:31 by rcammaro          #+#    #+#              #
#    Updated: 2021/04/15 19:34:54 by rcammaro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main_push_swap.c \
		choose_split.c \
		discard_stacks.c \
		dup_stacks.c \
		exit_program.c \
		ft_strtol_mv_ptr.c \
		get_median.c \
		parse_single_str.c \
		hybrid_quick_ins_sort_a_2.c \
		hybrid_quick_ins_sort_a.c \
		hybrid_quick_ins_sort_b_2.c \
		hybrid_quick_ins_sort_b.c \
		insertion_sort_a.c \
		insertion_sort_b.c \
		is_sorted.c \
		list_functions.c \
		merge_sort_a.c \
		merge_sort_b.c \
		op_push.c \
		op_rev_rotate.c \
		op_rotate.c \
		op_swap.c \
		optimize.c \
		opt_rotations_2.c \
		opt_rotations.c \
		quicksort.c \
		setup_stacks.c \
		sort_a_3.c \
		sort_a_4_1x.c \
		sort_a_4_2x.c \
		sort_a_4_3x.c \
		sort_a_4_4x.c \
		sort_a_4.c \
		sort_a_4_ultimate.c \
		sort_a.c \
		sort_b_3.c \
		sort_b_4_1x.c \
		sort_b_4_2x.c \
		sort_b_4_3x.c \
		sort_b_4_4x.c \
		sort_b_4.c \
		sort_b_4_ultimate.c \
		sort_b.c
		

SRCS_CHECKER =	main_checker.c \
				exit_program.c \
				ft_strtol_mv_ptr.c \
				setup_stacks.c \
				parse_single_str.c \
				list_functions.c \
				is_sorted.c \
				op_push.c \
				op_rev_rotate.c \
				op_rotate.c \
				op_swap.c \
				optimize.c \
				opt_rotations.c \
				opt_rotations_2.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./libft -I./includes

OBJS = $(patsubst %.c, obj/%.o, $(SRCS))
OBJS_CHECKER = $(patsubst %.c, obj/%.o, $(SRCS_CHECKER))

HEADER = includes/push_swap.h

LIBFT = libft/libft.a

NAME = push_swap
NAME_1 = checker

all:		$(NAME) $(NAME_1)

$(NAME):	$(LIBFT) $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -lft -L./libft -o $@

$(NAME_1):	$(LIBFT) $(OBJS_CHECKER)
			$(CC) $(CFLAGS) $(OBJS_CHECKER) -lft -L./libft -o $@

$(LIBFT):
			$(MAKE) all clean -C libft

obj/%.o:	src/%.c $(HEADER)
			@mkdir -p obj
			$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
			rm -f $(OBJS) $(OBJS_CHECKER)
			rm -rf obj

fclean:		clean
			rm -f $(NAME) $(NAME_1) $(LIBFT)

re:			fclean all

.PHONY:		all clean fclean re
