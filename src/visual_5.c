/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 20:31:29 by idunaver          #+#    #+#             */
/*   Updated: 2019/09/13 20:46:17 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		main_table_color(int width, int length, t_stack *stack_a,
t_stack *stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = NULL;
	tmp_b = NULL;
	if (stack_a)
		tmp_a = stack_a;
	if (stack_b)
		tmp_b = stack_b;
	while (length)
	{
		cell_color(width, tmp_a, tmp_b);
		if (!tmp_a || tmp_a->next->number == stack_a->number
		|| len_stack(stack_a) == 1)
			tmp_a = NULL;
		if (!tmp_b || tmp_b->next->number == stack_b->number
		|| len_stack(stack_b) == 1)
			tmp_b = NULL;
		if (tmp_a)
			tmp_a = tmp_a->next;
		if (tmp_b)
			tmp_b = tmp_b->next;
		length--;
	}
}
