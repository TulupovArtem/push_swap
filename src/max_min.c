/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 17:44:31 by idunaver          #+#    #+#             */
/*   Updated: 2019/08/15 17:52:54 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		min_num_in_stack(t_stack *stack_a)
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

int		max_num_in_stack(t_stack *stack_a)
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
