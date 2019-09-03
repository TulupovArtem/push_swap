/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:06:31 by idunaver          #+#    #+#             */
/*   Updated: 2019/09/03 16:53:36 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			what_swap(char **line, t_stack **stack_a, t_stack **stack_b)
{
	*line = *line + 1;
	if (**line == 'a')
		swap(stack_a, 0);
	else if (**line == 'b')
		swap(stack_b, 0);
	else if (**line == 's')
		double_swap(stack_a, stack_b, 0);
	else
		return ;
}

void			what_push(char **line, t_stack **stack_a, t_stack **stack_b)
{
	*line = *line + 1;
	if (**line == 'a')
		push_a(stack_a, stack_b, 0);
	else if (**line == 'b')
		push_b(stack_a, stack_b, 0);
	else
		return ;
}

void			what_rotate(char **line, t_stack **stack_a, t_stack **stack_b)
{
	if (**line == 'a')
		rotate(stack_a, 0);
	else if (**line == 'b')
		rotate(stack_b, 0);
	else if (**line == 'r')
		double_rotate(stack_a, stack_b, 0);
	else
		return ;
}

void			what_reverse_rotate(char **line,
t_stack **stack_a, t_stack **stack_b)
{
	*line = *line + 1;
	if (**line == 'a')
		reverse_rotate(stack_a, 0);
	else if (**line == 'b')
		reverse_rotate(stack_b, 0);
	else if (**line == 'r')
		double_reverse_rotate(stack_a, stack_b, 0);
	else
		return ;
}
