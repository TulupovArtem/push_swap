/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 16:09:55 by idunaver          #+#    #+#             */
/*   Updated: 2019/08/28 15:46:57 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack, int print)
{
	if (!*stack || (*stack)->next->number == (*stack)->number)
		return ;
	*stack = (*stack)->previous;
	if (print == 1)
		ft_putendl("rra");
	else if (print == 2)
		ft_putendl("rrb");
}

void	double_reverse_rotate(t_stack **stack_a, t_stack **stack_b, int print)
{
	reverse_rotate(stack_a, 0);
	reverse_rotate(stack_b, 0);
	if (print == 1)
		ft_putendl("rrr");
}
