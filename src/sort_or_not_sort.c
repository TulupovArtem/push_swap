/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_or_not_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 14:25:26 by idunaver          #+#    #+#             */
/*   Updated: 2019/08/28 16:01:09 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorting_check(t_stack *stack_a)
{
	t_stack	*tmp;

	tmp = stack_a;
	while (tmp->next->number != stack_a->number)
	{
		if (tmp->number < tmp->next->number)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

int	how_much_sorting(t_stack *stack_a)
{
	t_stack	*tmp;
	int		count;

	tmp = stack_a;
	count = 0;
	while (tmp->next->number != stack_a->number)
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