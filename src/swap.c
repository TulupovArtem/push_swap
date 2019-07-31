/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 16:08:33 by idunaver          #+#    #+#             */
/*   Updated: 2019/07/31 17:02:29 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*a;
	t_stack	*b;
	int		c;

	if (!*stack || (*stack)->next == *stack)
		return ;
	a = (*stack)->previous;
	b = a->previous;
	c = a->number;
	a->number = b->number;
	b->number = c;
}
