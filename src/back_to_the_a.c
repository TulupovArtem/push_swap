/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_to_the_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 20:23:47 by idunaver          #+#    #+#             */
/*   Updated: 2019/09/12 20:31:27 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		double_rr(t_stack **stack_a, t_stack **stack_b, t_count_op *tmp)
{
	while (tmp->op_a && tmp->op_b)
	{
		double_reverse_rotate(stack_a, stack_b, 1);
		tmp->op_a--;
		tmp->op_b--;
	}
	while (tmp->op_a--)
		reverse_rotate(stack_a, 1);
	while (tmp->op_b--)
		reverse_rotate(stack_b, 2);
}

static void		double_r(t_stack **stack_a, t_stack **stack_b, t_count_op *tmp)
{
	while (tmp->op_a && tmp->op_b)
	{
		double_rotate(stack_a, stack_b, 1);
		tmp->op_a--;
		tmp->op_b--;
	}
	while (tmp->op_a--)
		rotate(stack_a, 1);
	while (tmp->op_b--)
		rotate(stack_b, 2);
}

void			back_to_the_a(t_stack **stack_a, t_stack **stack_b,
t_count_op *oper, int number)
{
	t_count_op	*tmp;

	tmp = oper;
	while (number != tmp->number)
		tmp = tmp->next;
	if (tmp->rev_rot_b == 1 && tmp->rev_rot_a == 1)
		double_rr(stack_a, stack_b, tmp);
	else if (tmp->rev_rot_b == 0 && tmp->rev_rot_a == 0)
		double_r(stack_a, stack_b, tmp);
	else if (tmp->rev_rot_b == 0 && tmp->rev_rot_a == 1)
	{
		while (tmp->op_a--)
			reverse_rotate(stack_a, 1);
		while (tmp->op_b--)
			rotate(stack_b, 2);
	}
	else if (tmp->rev_rot_b == 1 && tmp->rev_rot_a == 0)
	{
		while (tmp->op_a--)
			rotate(stack_a, 1);
		while (tmp->op_b--)
			reverse_rotate(stack_b, 2);
	}
	push_a(stack_a, stack_b, 1);
	free_list_op(&oper);
}
