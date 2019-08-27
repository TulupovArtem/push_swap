/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 17:20:22 by idunaver          #+#    #+#             */
/*   Updated: 2019/08/27 18:16:45 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	back_to_the_a(t_stack **stack_a, t_stack **stack_b,
t_count_op *oper, int number)
{
	t_count_op *tmp;

	tmp = oper;
	while (number != tmp->number)
		tmp = tmp->next;
	if (tmp->rev_rot_b == 1)
		while (tmp->op_b--)
			reverse_rotate(stack_b, 1);
	else
		while (tmp->op_b--)
			rotate(stack_b, 1);
	if (tmp->rev_rot_a == 1)
		while (tmp->op_a--)
			reverse_rotate(stack_a, 1);
	else
		while (tmp->op_a--)
			rotate(stack_a, 1);
	push_a(stack_a, stack_b, 1);
	free_list_op(&oper);
}

void	moving_numbers(t_stack **stack_a, t_stack **stack_b, int arg)
{
	t_count_op	*oper;
	t_count_op	*tmp;
	int			number;
	int			min_op;

	oper = total_operations(*stack_a, *stack_b, arg);
	tmp = oper;
	number = tmp->number;
	min_op = tmp->sum_oper;
	while (tmp->next != NULL)
	{
		if (min_op > tmp->sum_oper)
		{
			number = tmp->number;
			min_op = tmp->sum_oper;
		}
		tmp = tmp->next;
	}
	back_to_the_a(stack_a, stack_b, oper, number);
}

void	sort_stack_a(t_stack **stack_a, int arg)
{
	int min;
	int max;

	min = min_num_in_stack(*stack_a);
	max = max_num_in_stack(*stack_a);
	if (arg <= 3)
	{
		while ((*stack_a)->number != max || (*stack_a)->next->number != min)
		{
			if ((*stack_a)->number == min)
				rotate(stack_a, 1);
			else if ((*stack_a)->previous->number == min)
				reverse_rotate(stack_a, 1);
			else if ((*stack_a)->number != min && (*stack_a)->number != max)
				swap(stack_a, 1);
		}
	}
	return ;
}

void	final_rotate(t_stack **stack_a)
{
	int		count;
	int		rev_count;
	t_stack	*tmp;

	count = 0;
	rev_count = 0;
	tmp = *stack_a;
	while (tmp->number != max_num_in_stack(*stack_a))
	{
		count++;
		tmp = tmp->next;
	}
	if (count > (len_a(*stack_a) / 2))
	{
		rev_count = len_a(*stack_a) - count;
		count = 0;
	}
	while (rev_count-- != 0)
		rotate(stack_a, 1);
	while (count-- != 0)
		reverse_rotate(stack_a, 1);
}

void	plan_drum(t_stack **stack_a, t_stack **stack_b, int arg)
{
	int numbers_push;
	int	count_sort;

	count_sort = how_much_sorting(*stack_a);
	if (count_sort < 3)
	{
		numbers_push = arg - 3;
		while (numbers_push--)
			push_b(stack_a, stack_b, 1);
		sort_stack_a(stack_a, 3);
		numbers_push = arg - 3;
		while (numbers_push-- != 0)
			moving_numbers(stack_a, stack_b, arg);
		final_rotate(stack_a);
	}
	else
	{
		numbers_push = arg - count_sort;
		final_rotate(stack_a);
		if (sorting_check(*stack_a) == 1)
			return ;
		while (numbers_push--)
			push_b(stack_a, stack_b, 1);
		numbers_push = arg - count_sort;
		while (numbers_push-- != 0)
			moving_numbers(stack_a, stack_b, arg);
		final_rotate(stack_a);
	}
}
