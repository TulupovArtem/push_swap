/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:02:59 by idunaver          #+#    #+#             */
/*   Updated: 2019/08/02 16:40:40 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int min_num_in_a(t_stack *stack_a)
{
	if (stack_a->number < stack_a->next->number && stack_a->number > stack_a->previous->number)
		return (stack_a->previous->number);
	else if (stack_a->number < stack_a->previous->number && stack_a->number > stack_a->next->number)
		return (stack_a->next->number);
	return (stack_a->number);
}

int max_num_in_a(t_stack *stack_a)
{
	if (stack_a->number < stack_a->next->number && stack_a->number > stack_a->previous->number)
		return (stack_a->next->number);
	else if (stack_a->number < stack_a->previous->number && stack_a->number > stack_a->next->number)
		return (stack_a->previous->number);
	return (stack_a->number);
}

void	sort_stack_a(t_stack **stack_a, int arg)
{
	int min;
	int max;

	min = min_num_in_a(*stack_a);
	max = max_num_in_a(*stack_a);
	printf("stack_a->number: %d\n", (*stack_a)->number);
	printf("max: %d;\nmin: %d;\narg: %d\n", max, min, arg);
	return ;
}

void	sort_numbers(t_stack *stack_a, t_stack *stack_b, int arg)
{
	stack_b = NULL;
	if (arg <= 3)
		sort_stack_a(&stack_a, arg);
	return ;
}

int		main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack *stack_b;
	int 	arg;

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
