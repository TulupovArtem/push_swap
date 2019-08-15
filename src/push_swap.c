/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:02:59 by idunaver          #+#    #+#             */
/*   Updated: 2019/08/15 16:04:26 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		min_num_in_a(t_stack *stack_a)
{
	t_stack	*head;
	t_stack	*tmp;
	int		min;

	tmp = stack_a;
	head = stack_a;
	min = head->number;
	while (tmp->next->number != head->number)
	{
		if (tmp->next->number < min)
			min = tmp->next->number;
		tmp = tmp->next;
	}
	return (min);
}

int		max_num_in_a(t_stack *stack_a)
{
	t_stack	*head;
	t_stack	*tmp;
	int		max;

	tmp = stack_a;
	head = stack_a;
	max = head->number;
	while (tmp->next->number != head->number)
	{
		if (tmp->next->number > max)
			max = tmp->next->number;
		tmp = tmp->next;
	}
	return (max);
}

void	sort_stack_a(t_stack **stack_a, t_stack **stack_b, int arg)
{
	int min;
	int max;

	min = min_num_in_a(*stack_a);
	max = max_num_in_a(*stack_a);
	printf("head1: %d\n", (*stack_a)->number);
	printf("end1: %d\n", (*stack_a)->next->number);
	if (arg <= 3)
	{
		if ((*stack_a)->number == min && (*stack_a)->next->number == max)
		{
			printf("ok");
			return ;
		}
		if ((*stack_a)->number == max)
		{
			push_b(stack_a, stack_b);
			push_b(stack_a, stack_b);
		}
	}
	printf("head2: %d\n", (*stack_a)->number);
	printf("end2: %d\n", (*stack_a)->next->number);
	return ;
}

void	sort_numbers(t_stack *stack_a, t_stack *stack_b, int arg)
{
	stack_b = NULL;
	if (arg <= 3)
		sort_stack_a(&stack_a, &stack_b, arg);
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
