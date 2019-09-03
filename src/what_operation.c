/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:06:31 by idunaver          #+#    #+#             */
/*   Updated: 2019/09/03 18:02:40 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			what_swap(char **line, t_stack **stack_a, t_stack **stack_b)
{
	*line = *line + 1;
	if (**line == 'a' && *(*line + 2) != ' ')
	{
		swap(stack_a, 0);
		return (0);
	}
	else if (**line == 'b' && *(*line + 2) != ' ')
	{
		swap(stack_b, 0);
		return (0);
	}
	else if (**line == 's' && *(*line + 2) != ' ')
	{
		double_swap(stack_a, stack_b, 0);
		return (0);
	}
	else
	{
		ft_putendl("Error");
		return (-1);
	}
}

int			what_push(char **line, t_stack **stack_a, t_stack **stack_b)
{
	*line = *line + 1;
	if (**line == 'a' && *(*line + 2) != ' ')
	{
		push_a(stack_a, stack_b, 0);
		return (0);
	}
	else if (**line == 'b' && *(*line + 2) != ' ')
	{
		push_b(stack_a, stack_b, 0);
		return (0);
	}
	else
	{
		ft_putendl("Error");
		return (-1);
	}
}

int			what_rotate(char **line, t_stack **stack_a, t_stack **stack_b)
{
	if (**line == 'a' && *(*line + 2) != ' ')
	{
		rotate(stack_a, 0);
		return (0);
	}
	else if (**line == 'b' && *(*line + 2) != ' ')
	{
		rotate(stack_b, 0);
		return (0);
	}
	else if (**line == 'r' && *(*line + 2) != ' ')
	{
		double_rotate(stack_a, stack_b, 0);
		return (0);
	}
	else
	{
		ft_putendl("Error");
		return (-1);
	}
}

int			what_reverse_rotate(char **line,
t_stack **stack_a, t_stack **stack_b)
{
	*line = *line + 1;
	if (**line == 'a' && *(*line + 2) != ' ')
	{
		reverse_rotate(stack_a, 0);
		return (0);
	}
	else if (**line == 'b' && *(*line + 2) != ' ')
	{
		reverse_rotate(stack_b, 0);
		return (0);
	}
	else if (**line == 'r' && *(*line + 2) != ' ')
	{
		double_reverse_rotate(stack_a, stack_b, 0);
		return (0);
	}
	else
	{
		ft_putendl("Error");
		return (-1);
	}
}
