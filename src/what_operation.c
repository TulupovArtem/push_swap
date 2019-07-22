/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:06:31 by idunaver          #+#    #+#             */
/*   Updated: 2019/07/22 17:33:36 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			what_swap(char **line, t_stack *stack_a, t_stack *stack_b)
{
	if (**line == 'a')
		swap(stack_a);
	else if (**line == 'b')
		swap(stack_b);
	else if (**line == 's')
	{
		swap(stack_a);
		swap(stack_b);
	}
	else
		return ;
}

void			what_push(char **line, t_stack *stack_a, t_stack *stack_b)
{
	if (**line == 'a')
		push_a(stack_a, stack_b);
	else if (**line == 'b')
		push_b(stack_a, stack_b);
	else
		return ;
}

void			what_rotate(char **line, t_stack **stack_a, t_stack **stack_b)
{
	if (**line == 'a')
		rotate(stack_a);
	else if (**line == 'b')
		rotate(stack_b);
	else if (**line == 'r')
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else
		return ;
}

void			what_reverse_rotate(char **line, t_stack *stack_a, t_stack *stack_b)
{
	if (**line == 'a')
		reverse_rotate(stack_a);
	else if (**line == 'b')
		reverse_rotate(stack_b);
	else if (**line == 'r')
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
	}
	else
		return ;
}
