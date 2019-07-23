/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 16:08:48 by idunaver          #+#    #+#             */
/*   Updated: 2019/07/23 10:30:34 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_b)
		return ;
	if (!*stack_a)
	{
		init_stack((*stack_b)->previous->number);
		del_first_elem_in_stack(*stack_b);
	}
	else
	{
		add_num_in_stack((*stack_b)->previous->number, *stack_a);
		del_first_elem_in_stack(*stack_b);
	}
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_a)
		return ;
	if (!*stack_b)
	{
		init_stack((*stack_a)->previous->number);
		del_first_elem_in_stack(*stack_a);
	}
	else
	{
		add_num_in_stack((*stack_a)->previous->number, *stack_b);
		del_first_elem_in_stack(*stack_a);
	}
}
