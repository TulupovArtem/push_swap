/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_or_not_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 14:25:26 by idunaver          #+#    #+#             */
/*   Updated: 2019/08/23 14:31:22 by idunaver         ###   ########.fr       */
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