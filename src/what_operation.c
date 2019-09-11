/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:06:31 by idunaver          #+#    #+#             */
/*   Updated: 2019/09/11 20:53:00 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			what_swap(char **line, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(*line, "sa") == 0)
		swap(stack_a, 0);
	else if (ft_strcmp(*line, "sb") == 0)
		swap(stack_b, 0);
	else if (ft_strcmp(*line, "ss") == 0)
		double_swap(stack_a, stack_b, 0);
	else
	{
		ft_putendl("Error");
		return ;
	}
}

void			what_push(char **line, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(*line, "pa") == 0)
		push_a(stack_a, stack_b, 0);
	else if (ft_strcmp(*line, "pb") == 0)
		push_b(stack_a, stack_b, 0);
	else
	{
		ft_putendl("Error");
		return ;
	}
}

void			what_rotate(char **line, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(*line, "ra") == 0)
		rotate(stack_a, 0);
	else if (ft_strcmp(*line, "rb") == 0)
		rotate(stack_b, 0);
	else if (ft_strcmp(*line, "rr") == 0)
		double_rotate(stack_a, stack_b, 0);
	else
	{
		ft_putendl("Error");
		return ;
	}
}

void			what_reverse_rotate(char **line,
t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(*line, "rra") == 0)
		reverse_rotate(stack_a, 0);
	else if (ft_strcmp(*line, "rrb") == 0)
		reverse_rotate(stack_b, 0);
	else if (ft_strcmp(*line, "rrr") == 0)
		double_reverse_rotate(stack_a, stack_b, 0);
	else
	{
		ft_putendl("Error");
		return ;
	}
}
