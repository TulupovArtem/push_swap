/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 20:49:27 by idunaver          #+#    #+#             */
/*   Updated: 2019/09/11 22:45:03 by idunaver         ###   ########.fr       */
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

void		stack_number_output(t_stack **stack_a, t_stack **stack_b,
int max_len)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	while (max_len--)
	{
		if (tmp_a && tmp_b && tmp_a->next->number != (*stack_a)->number
		&& tmp_b->next->number != (*stack_b)->number && tmp_a->number >= 0
		&& tmp_b->number >= 0)
			printf("| %lld  | %lld |\n", tmp_a->number, tmp_b->number);
		else if (tmp_a && tmp_a->next->number != (*stack_a)->number
		&& tmp_a->number >= 0)
			printf("| %lld  |    |\n", tmp_a->number);
		else if (tmp_b && tmp_b->next->number != (*stack_b)->number
		&& tmp_b->number >= 0)
			printf("|    | %lld  |\n", tmp_b->number);
		else if (tmp_a && tmp_b && tmp_a->next->number != (*stack_a)->number
		&& tmp_b->next->number != (*stack_b)->number && tmp_a->number < 0
		&& tmp_b->number < 0)
			printf("| %lld | %lld |\n", tmp_a->number, tmp_b->number);
		else if (tmp_a && tmp_a->next->number != (*stack_a)->number
		&& tmp_a->number < 0)
			printf("| %lld |    |\n", tmp_a->number);
		else if (tmp_b && tmp_b->next->number != (*stack_b)->number
		&& tmp_b->number < 0)
			printf("|    | %lld |\n", tmp_b->number);
		if (tmp_a && tmp_a->next->number != (*stack_a)->number)
			tmp_a = tmp_a->next;
		if (tmp_b && tmp_b->next->number != (*stack_b)->number)
			tmp_b = tmp_b->next;
	}
}

void		visual_stacks(t_stack **stack_a, t_stack **stack_b, int visual)
{
	int		len_a;
	int		len_b;
	int		max_len;

	if (visual == 0)
		return ;
	len_a = len_stack(*stack_a);
	len_b = len_stack(*stack_b);
	printf(" ---- ----\n");
	printf("| a  | b  |\n");
	printf(" ---- ----\n");
	if (len_a > len_b)
		max_len = len_a;
	else
		max_len = len_b;
	stack_number_output(stack_a, stack_b, max_len);
	printf(" ---- ----\n");
}
