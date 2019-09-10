/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:12:33 by idunaver          #+#    #+#             */
/*   Updated: 2019/09/10 20:45:45 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count_sort_not_three(t_stack **stack_a, t_stack **stack_b, int arg)
{
	int numbers_push;
	int	count_sort;

	count_sort = how_much_sorting(*stack_a);
	numbers_push = arg - count_sort;
	if (sorting_check(*stack_a) == 1)
		return ;
	while (numbers_push--)
		push_b(stack_a, stack_b, 1);
	numbers_push = arg - count_sort;
	while (numbers_push-- != 0)
		moving_numbers(stack_a, stack_b, arg, count_sort++);
	final_rotate(stack_a);
}

void	plan_drum(t_stack **stack_a, t_stack **stack_b, int arg)
{
	int numbers_push;
	int	count_sort;

	count_sort = how_much_sorting(*stack_a);
	if (count_sort <= 3)
	{
		count_sort = 3;
		numbers_push = arg - count_sort;
		while (numbers_push--)
			push_b(stack_a, stack_b, 1);
		sort_stack_a(stack_a, 3);
		numbers_push = arg - count_sort;
		while (numbers_push-- != 0)
			moving_numbers(stack_a, stack_b, arg, count_sort++);
		final_rotate(stack_a);
	}
	else
		count_sort_not_three(stack_a, stack_b, arg);
}

void	sort_numbers(t_stack **stack_a, t_stack **stack_b, int arg)
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
