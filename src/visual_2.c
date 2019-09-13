/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 20:32:02 by idunaver          #+#    #+#             */
/*   Updated: 2019/09/13 20:38:15 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			len_stack(t_stack *stack)
{
	t_stack	*head;
	int		len;

	len = 1;
	if (!stack)
		return (0);
	head = stack;
	while (stack->previous->number != head->number)
	{
		stack = stack->previous;
		len++;
	}
	return (len);
}

void		line(int max_len)
{
	int	tmp_max_len;

	tmp_max_len = max_len;
	while (tmp_max_len--)
		ft_printf("-");
	ft_printf(" ");
	tmp_max_len = max_len;
	while (tmp_max_len--)
		ft_printf("-");
	ft_printf("\n");
}

int			count_numbers_in_n(int number)
{
	int count;

	count = 0;
	if (number == 0)
		return (1);
	if (number < 0)
		number *= -1;
	while (number)
	{
		number = number / 10;
		count++;
	}
	return (count);
}

int			max_of_two(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int			search_width(t_stack *stack_a, t_stack *stack_b)
{
	int		max_a;
	int		min_a;
	int		max_b;
	int		min_b;

	max_a = 0;
	min_a = 0;
	max_b = 0;
	min_b = 0;
	if (stack_a)
	{
		max_a = count_numbers_in_n(max_num_in_stack(stack_a));
		min_a = count_numbers_in_n(min_num_in_stack(stack_a));
		if (min_num_in_stack(stack_a) < 0)
			min_a++;
	}
	if (stack_b)
	{
		max_b = count_numbers_in_n(max_num_in_stack(stack_b));
		min_b = count_numbers_in_n(min_num_in_stack(stack_b));
		if (min_num_in_stack(stack_b) < 0)
			min_b++;
	}
	return (max_of_two(max_of_two(max_a, min_a), max_of_two(max_b, min_b)));
}
