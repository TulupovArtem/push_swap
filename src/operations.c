/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 19:11:34 by idunaver          #+#    #+#             */
/*   Updated: 2019/08/16 20:39:12 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			counting_operations_in_a(t_stack *stack_a, int number)
{
	stack_a = NULL;
	number = 0;
	return (0);
}

void		fill_list_opt(t_stack *stack_b, t_stack *stack_a,
int count_num, t_count_op *oper)
{
	int	operations;

	operations = 0;
	while ((count_num / 2) != operations)
	{
		stack_b = stack_b->previous;
		add_elem_in_list_op(stack_b->number,
		counting_operations_in_a(stack_a, stack_b->number), ++operations, oper);
		oper = oper->next;
	}
	if ((count_num / 2) % 2 == 0)
	{
		stack_b = stack_b->previous;
		add_elem_in_list_op(stack_b->number,
		counting_operations_in_a(stack_a, stack_b->number), operations, oper);
		oper = oper->next;
	}
	while (operations != 0)
	{
		stack_b = stack_b->previous;
		add_elem_in_list_op(stack_b->number,
		counting_operations_in_a(stack_a, stack_b->number), operations--, oper);
		oper = oper->next;
	}
}

t_count_op	*total_operations(t_stack *stack_a, t_stack *stack_b, int arg)
{
	t_count_op	*oper;
	int			count_num;

	count_num = arg - 3;
	oper = init_list_op(stack_b->number,
	counting_operations_in_a(stack_a, stack_b->number), 0);
	fill_list_opt(stack_b, stack_a, count_num, oper);
	return (oper);
}
