/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 16:08:48 by idunaver          #+#    #+#             */
/*   Updated: 2019/07/19 18:48:56 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_b)
		return ;
	add_num_in_stack(stack_b->previous->number, stack_a);
	del_first_elem_in_stack(stack_b);
}

void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a)
		return ;
	add_num_in_stack(stack_a->previous->number, stack_b);
	del_first_elem_in_stack(stack_a);
}
