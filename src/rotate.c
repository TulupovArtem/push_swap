/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 16:09:00 by idunaver          #+#    #+#             */
/*   Updated: 2019/08/15 16:43:31 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack, int print)
{
	if (!*stack || (*stack)->next->number == (*stack)->number)
		return ;
	*stack = (*stack)->previous;
	if (print == 1)
		ft_putendl("ra");
	else if (print == 2)
		ft_putendl("rb");
}

void	double_rotate(t_stack **stack_a, t_stack **stack_b, int print)
{
	rotate(stack_a, 0);
	rotate(stack_b, 0);
	if (print == 1)
		ft_putendl("rr");
}
