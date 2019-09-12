/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:06:31 by idunaver          #+#    #+#             */
/*   Updated: 2019/09/12 15:09:53 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			what_swap(char **line, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(*line, "sa") == 0)
	{
		swap(stack_a, 0);
		return (1);
	}
	else if (ft_strcmp(*line, "sb") == 0)
	{
		swap(stack_b, 0);
		return (1);
	}
	else if (ft_strcmp(*line, "ss") == 0)
	{
		double_swap(stack_a, stack_b, 0);
		return (1);
	}
	else
		return (0);
}

int			what_push(char **line, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(*line, "pa") == 0)
	{
		push_a(stack_a, stack_b, 0);
		return (1);
	}
	else if (ft_strcmp(*line, "pb") == 0)
	{
		push_b(stack_a, stack_b, 0);
		return (1);
	}
	else
		return (0);
}

int			what_rotate(char **line, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(*line, "ra") == 0)
	{
		rotate(stack_a, 0);
		return (1);
	}
	else if (ft_strcmp(*line, "rb") == 0)
	{
		rotate(stack_b, 0);
		return (1);
	}
	else if (ft_strcmp(*line, "rr") == 0)
	{
		double_rotate(stack_a, stack_b, 0);
		return (1);
	}
	else
		return (0);
}

int			what_reverse_rotate(char **line,
t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(*line, "rra") == 0)
	{
		reverse_rotate(stack_a, 0);
		return (1);
	}
	else if (ft_strcmp(*line, "rrb") == 0)
	{
		reverse_rotate(stack_b, 0);
		return (1);
	}
	else if (ft_strcmp(*line, "rrr") == 0)
	{
		double_reverse_rotate(stack_a, stack_b, 0);
		return (1);
	}
	else
		return (0);
}
