/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:02:59 by idunaver          #+#    #+#             */
/*   Updated: 2019/08/15 18:06:19 by idunaver         ###   ########.fr       */
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
	while ()
}

void	sort_numbers(t_stack *stack_a, t_stack *stack_b, int arg)
{
	stack_b = NULL;
	if (arg == 1)
		return ;
	if (arg <= 3)
		sort_stack_a(&stack_a, arg);
	else
		plan_drum(&stack_a, &stack_b, arg);
	return ;
}

int		main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack *stack_b;
	int		arg;

	arg = ac - 1;
	stack_b = NULL;
	stack_a = NULL;
	if (ac == 1)
		return (0);
	else
	{
		if (check_number(++av, ac) == 1)
		{
			ac--;
			stack_a = init_stack(ft_atoi(*av));
			while (--ac != -1 && *(++av))
				add_num_in_stack(ft_atoi(*av), stack_a);
			sort_numbers(stack_a->previous, stack_b, arg);
		}
		else
			ft_putendl("Error");
	}
	return (0);
}
