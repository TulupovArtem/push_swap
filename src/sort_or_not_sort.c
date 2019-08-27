/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_or_not_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 14:25:26 by idunaver          #+#    #+#             */
/*   Updated: 2019/08/27 17:00:26 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorting_check(t_stack *stack_a)
{
	t_stack	*tmp;

	tmp = stack_a;
	while (tmp->previous->number != stack_a->number)
	{
		if (tmp->number > tmp->previous->number)
			tmp = tmp->previous;
		else
			return (0);
	}
	return (1);
}

int	how_much_sorting(t_stack *stack_a)
{
	t_stack	*tmp;
	int		count;

	tmp = stack_a->next;
	count = 1;
	while (tmp->next->number != stack_a->next->number)
	{
		if (tmp->number < tmp->next->number)
		{
			tmp = tmp->next;
			count++;
		}
		else
			return (count);
	}
	return (count);
}