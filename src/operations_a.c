/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 18:55:30 by idunaver          #+#    #+#             */
/*   Updated: 2019/09/04 20:49:08 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			len_a(t_stack *stack_a)
{
	t_stack	*head;
	int		len;

	len = 1;
	head = stack_a;
	while (stack_a->previous->number != head->number)
	{
		stack_a = stack_a->previous;
		len++;
	}
	return (len);
}

int			number_not_min_and_not_max(int number, t_stack *stack_a)
{
	int		count;
	int		len;
	t_stack	*tmp;

	tmp = stack_a;
	len = len_a(stack_a);
	count = 0;
	while (tmp->number != min_num_in_stack(stack_a))
	{
		tmp = tmp->next;
		count++;
	}
	while (number > tmp->number)
	{
		tmp = tmp->next;
		count++;
	}
	if (count > len / 2)
	{
		count = len - count;
		count *= -1;
	}
	return (count);
}

int			count_a(int number, t_stack *stack_a, int max, int min)
{
	if (number < min && stack_a->number == max)
		return (1);
	if (number < max && number > min)
		return (number_not_min_and_not_max(number, stack_a));
	if (number > max && stack_a->previous->number == min)
		return (-1);
	if (number < min && number < max && stack_a->number != max)
		return (number_not_min_and_not_max(number, stack_a));
	return (0);
}

int			counting_operations_in_a(t_stack *stack_a, int number)
{
	int min;
	int max;

	min = min_num_in_stack(stack_a);
	max = max_num_in_stack(stack_a);
	if (number < stack_a->number && number > stack_a->previous->number)
		return (0);
	if (max < number && stack_a->number == min)
		return (0);
	else if (min > number && stack_a->previous->number == min && stack_a->number == max)
		return (0);
	else
		return (count_a(number, stack_a, max, min));
}
