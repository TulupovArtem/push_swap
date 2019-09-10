/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 19:11:34 by idunaver          #+#    #+#             */
/*   Updated: 2019/09/10 20:06:59 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		count_num_not_even(t_stack *stack_b, t_stack *stack_a,
int count_num, t_count_op **oper)
{
	int			operations;
	int			head_number;
	t_count_op	*tmp;

	tmp = *oper;
	operations = 1;
	head_number = stack_b->number;
	while ((count_num / 2) + 1 != operations)
	{
		stack_b = stack_b->next;
		add_elem_in_list_op(stack_b->number,
		counting_operations_in_a(stack_a, stack_b->number), operations++, oper);
		tmp = tmp->next;
	}
	while (operations != 0)
	{
		stack_b = stack_b->next;
		if (stack_b->number == head_number)
			return ;
		add_elem_in_list_op(stack_b->number,
		counting_operations_in_a(stack_a, stack_b->number), --operations, oper);
		tmp = tmp->next;
		tmp->rev_rot_b = 1;
	}
}

void		count_num_even(t_stack *stack_b, t_stack *stack_a,
int count_num, t_count_op **oper)
{
	int			operations;
	int			head_number;
	t_count_op	*tmp;

	tmp = *oper;
	operations = 1;
	head_number = stack_b->number;
	while ((count_num / 2) + 1 != operations)
	{
		stack_b = stack_b->next;
		add_elem_in_list_op(stack_b->number,
		counting_operations_in_a(stack_a, stack_b->number), operations++, oper);
		tmp = tmp->next;
	}
	--operations;
	while (operations != 0)
	{
		stack_b = stack_b->next;
		if (stack_b->number == head_number)
			return ;
		add_elem_in_list_op(stack_b->number,
		counting_operations_in_a(stack_a, stack_b->number), --operations, oper);
		tmp = tmp->next;
		tmp->rev_rot_b = 1;
	}
}

void		fill_list_opt(t_stack *stack_b, t_stack *stack_a,
int count_num, t_count_op **oper)
{
	if (count_num % 2 == 0)
		count_num_even(stack_b, stack_a, count_num, oper);
	else
		count_num_not_even(stack_b, stack_a, count_num, oper);
}

t_count_op	*total_operations(t_stack *stack_a, t_stack *stack_b,
int arg, int count_sort)
{
	t_count_op	*oper;
	int			count_num;

	count_num = arg - count_sort;
	oper = init_list_op(stack_b->number,
	counting_operations_in_a(stack_a, stack_b->number), 0);
	fill_list_opt(stack_b, stack_a, count_num, &oper);
	return (oper);
}
