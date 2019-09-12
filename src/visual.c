/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 20:49:27 by idunaver          #+#    #+#             */
/*   Updated: 2019/09/12 21:21:35 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		cell(int width, t_stack *stack_a, t_stack *stack_b)
{
	int tmp;
	int len_a;
	int len_b;

	len_a = 0;
	len_b = 0;
	tmp = 0;
	if (stack_a)
	{
		len_a = count_numbers_in_n(stack_a->number);
		if (stack_a->number < 0)
			len_a++;
	}
	if (stack_b)
	{
		len_b = count_numbers_in_n(stack_b->number);
		if (stack_b->number < 0)
			len_b++;
	}
	printf("| ");
	tmp = (width - len_a - 3) / 2;
	while (tmp--)
		printf(" ");
	if (stack_a)
		printf("%lld", stack_a->number);
	tmp = (width - len_a - 2) / 2;
	while (tmp--)
		printf(" ");
	printf(" | ");
	tmp = (width - len_b - 2) / 2;
	while (tmp--)
		printf(" ");
	if (stack_b)
		printf("%lld", stack_b->number);
	tmp = (width - len_b - 3) / 2;
	while (tmp--)
		printf(" ");
	printf(" |\n");
}

void		main_table(int width, int length, t_stack *stack_a,
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
		cell(width, tmp_a, tmp_b);
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

int			search_length(t_stack *stack_a, t_stack *stack_b)
{
	int		len_a;
	int		len_b;

	len_a = 0;
	len_b = 0;
	len_a = len_stack(stack_a);
	len_b = len_stack(stack_b);
	if (len_a > len_b)
		return (len_a);
	else
		return (len_b);
}

void		visual_stacks(t_stack **stack_a, t_stack **stack_b,
int visual)
{
	int		length;
	int		width;

	length = 0;
	width = 0;
	if (visual == 0)
		return ;
	width = search_width(*stack_a, *stack_b) + 3;
	length = search_length(*stack_a, *stack_b);
	head_table(width);
	main_table(width, length, *stack_a, *stack_b);
	line(width);
}
