/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:06:43 by idunaver          #+#    #+#             */
/*   Updated: 2019/08/16 20:29:33 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>

typedef struct			s_stack
{
	int					number;
	struct s_stack		*next;
	struct s_stack		*previous;
}						t_stack;

typedef struct			s_count_op
{
	int					op_a;
	int					op_b;
	int					sum_oper;
	int					number;
	struct s_count_op	*next;
	struct s_count_op	*previous;
}						t_count_op;

/* check_number.c */
int					check_number(char **number, int ac);

/* work_with_stack.c */
void				free_stacks(t_stack *stack_a, t_stack *stack_b);
void				del_first_elem_in_stack(t_stack **stack);
void				add_num_in_stack(int number, t_stack *stack);
t_stack				*init_stack(int number);

/* what_operation.c */
void				what_reverse_rotate(char **line, t_stack **stack_a, t_stack **stack_b);
void				what_rotate(char **line, t_stack **stack_a, t_stack **stack_b);
void				what_push(char **line, t_stack **stack_a, t_stack **stack_b);
void				what_swap(char **line, t_stack **stack_a, t_stack **stack_b);

/* swap.c */
void				swap(t_stack **stack, int print);
void				double_swap(t_stack **stack_a, t_stack **stack_b, int print);

/* push.c */
void				push_a(t_stack **stack_a, t_stack **stack_b, int print);
void				push_b(t_stack **stack_a, t_stack **stack_b, int print);

/* rotate.c */
void				rotate(t_stack **stack, int print);
void				double_rotate(t_stack **stack_a, t_stack **stack_b, int print);

/* reverse_rotate.c */
void				reverse_rotate(t_stack **stack, int print);
void				double_reverse_rotate(t_stack **stack_a, t_stack **stack_b, int print);

/* max_min.c */
int					min_num_in_stack(t_stack *stack_a);
int					max_num_in_stack(t_stack *stack_a);

/* algorythm.c */
void				plan_drum(t_stack **stack_a, t_stack **stack_b, int arg);
void				sort_stack_a(t_stack **stack_a, int arg);
void				moving_numbers(t_stack **stack_a, t_stack **stack_b, int arg);

/* operations.c */
t_count_op			*total_operations(t_stack *stack_a, t_stack *stack_b, int arg);
int 				counting_operations_in_a(t_stack *stack_a, int number);
void				fill_list_opt(t_stack *stack_b, t_stack *stack_a, int count_num, t_count_op *oper);

/* work_with_list_op.c */
t_count_op  		*init_list_op(int number, int op_a, int op_b);
void  				add_elem_in_list_op(int number, int op_a, int op_b, t_count_op *oper);
void 				free_list_op(t_count_op *oper);

#endif
