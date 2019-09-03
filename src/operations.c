/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 19:11:34 by idunaver          #+#    #+#             */
/*   Updated: 2019/09/03 15:19:44 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	back_to_the_push_swap(long long *n, t_stack **stack_a, t_stack **stack_b, int count)
{
	int arg;

	arg = count;
	if (!(*n > INT_MAX) && !(*n < INT_MIN))
	{
		*stack_a = init_stack(*n);
		while (--count && ++n)
		{
			if (!(*n > INT_MAX) && !(*n < INT_MIN))
				add_num_in_stack(*n, *stack_a);
			else
			{
				ft_putendl("Error");
				return ;
			}
		}
		sort_numbers(stack_a, stack_b, arg);
		free_stacks(*stack_a, *stack_b);
	}
	else
		ft_putendl("Error");
}

void		sort_numbers(t_stack **stack_a, t_stack **stack_b, int arg)
{
	if (sorting_check(*stack_a) == 1)
		return ;
	if (arg == 1)
		return ;
	if (arg <= 3)
		sort_stack_a(stack_a, arg);
	else
		plan_drum(stack_a, stack_b, arg);
	return ;
}

void		exception_in_reverse_opt(int number, t_stack *stack_a, t_count_op **oper, int head_number)
{
	t_count_op *tmp;

	if (number == head_number)
		return ;
	add_elem_in_list_op(number,
	counting_operations_in_a(stack_a, number), 1, oper);
	tmp = *oper;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->rev_rot_b = 1;
}

void		fill_list_opt(t_stack *stack_b, t_stack *stack_a,
int count_num, t_count_op **oper)
{
	int			operations;
	int 		head_number;
	t_count_op	*tmp;

	tmp = *oper;
	head_number = stack_b->number;
	operations = 0;
	while ((count_num / 2) != operations)
	{
		stack_b = stack_b->next;
		add_elem_in_list_op(stack_b->number,
		counting_operations_in_a(stack_a, stack_b->number), ++operations, oper);
		tmp = tmp->next;
	}
	if ((count_num / 2) % 2 == 0 && count_num % 2 != 0 && operations != count_num - 1)
	{
		stack_b = stack_b->next;
		add_elem_in_list_op(stack_b->number,
		counting_operations_in_a(stack_a, stack_b->number), operations, oper);
		tmp = tmp->next;
	}
	if (operations == 1 && stack_b->number != head_number)
	{
		exception_in_reverse_opt(stack_b->next->number, stack_a, oper, head_number);
		return ;
	}
	while (operations != 0 && operations != count_num - 1)
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

t_count_op	*total_operations(t_stack *stack_a, t_stack *stack_b, int arg, int count_sort)
{
	t_count_op	*oper;
	int			count_num;

	count_num = arg - count_sort;
	oper = init_list_op(stack_b->number,
	counting_operations_in_a(stack_a, stack_b->number), 0);
	fill_list_opt(stack_b, stack_a, count_num, &oper);
	return (oper);
}
