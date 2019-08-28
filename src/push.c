/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 16:08:48 by idunaver          #+#    #+#             */
/*   Updated: 2019/08/28 16:58:18 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack **stack_a, t_stack **stack_b, int print)
{
	if (!*stack_b)
		return ;
	if (!*stack_a)
	{
		*stack_a = init_stack((*stack_b)->number);
		del_first_elem_in_stack(stack_b);
	}
	else
	{
		add_num_in_stack((*stack_b)->number, *stack_a);
		reverse_rotate(stack_a, 0);
		del_first_elem_in_stack(stack_b);
	}
	if (print == 1)
		ft_putendl("pa");
}

void	push_b(t_stack **stack_a, t_stack **stack_b, int print)
{
	if (!*stack_a)
		return ;
	if (!*stack_b)
	{
		*stack_b = init_stack((*stack_a)->number);
		del_first_elem_in_stack(stack_a);
	}
	else
	{
		add_num_in_stack((*stack_a)->number, *stack_b);
		reverse_rotate(stack_b, 0);
		del_first_elem_in_stack(stack_a);
	}
	if (print == 1)
		ft_putendl("pb");
}
