/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 19:11:34 by idunaver          #+#    #+#             */
/*   Updated: 2019/08/22 16:47:47 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			len_a(t_stack *stack_a)
{
	t_stack	*head;
	int		len;

	len = 1;
	head = stack_a;
	while (stack_a->previous->number != head->number)
	{
		stack_a = stack_a->previous;
		len++;
	}
	return (len);
}

int			count_a(int number, t_stack *stack_a, int max, int min)
{
	int count;
	int len;

	count = 0;
	len = len_a(stack_a);
	if (number > max && stack_a->number == min)
		return (1);
	if (number < max && number > min)
	{
		while (number < stack_a->number)
		{
			stack_a = stack_a->previous;
			count++;
		}
		if (count > len / 2)
		{
			count = len - count;
			count *= -1;
		}
	}
	if (number > max && stack_a->next->number == max)
		count = -1;
	return (count);
}

int			counting_operations_in_a(t_stack *stack_a, int number)
{
	int min;
	int max;

	min = min_num_in_stack(stack_a);
	max = max_num_in_stack(stack_a);
	if (max < number && stack_a->number == max)
		return (0);
	else if (min > number && stack_a->next->number == min)
		return (0);
	else
		return (count_a(number, stack_a, max, min));
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
		counting_operations_in_a(stack_a, stack_b->number), --operations, oper);
		oper->rev_rot_b = 1;
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
