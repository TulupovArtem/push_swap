/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 17:20:22 by idunaver          #+#    #+#             */
/*   Updated: 2019/08/16 17:22:27 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	plan_drum(t_stack **stack_a, t_stack **stack_b, int arg)
{
	int numbers_push;

	numbers_push = arg - 3;
	while (numbers_push--)
		push_b(stack_a, stack_b, 1);
	sort_stack_a(stack_a, 3);
}