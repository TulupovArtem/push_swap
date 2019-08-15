/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 16:08:33 by idunaver          #+#    #+#             */
/*   Updated: 2019/08/15 16:32:20 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, int print)
{
	t_stack	*a;
	t_stack	*b;
	int		c;

	if (!*stack || (*stack)->next == *stack)
		return ;
	a = *stack;
	b = a->previous;
	c = a->number;
	a->number = b->number;
	b->number = c;
	if (print == 1)
		ft_putendl("sa");
	else if (print == 2)
		ft_putendl("sb");
}

void	double_swap(t_stack **stack_a, t_stack **stack_b, int print)
{
	swap(stack_a, 0);
	swap(stack_b, 0);
	if (print == 1)
		ft_putendl("ss");
}
