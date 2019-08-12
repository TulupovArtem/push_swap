/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 18:39:13 by idunaver          #+#    #+#             */
/*   Updated: 2019/08/12 21:25:24 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp;

	tmp = NULL;
	while (stack_a)
	{
		tmp = stack_a->next;
		free(stack_a);
		stack_a = tmp;
	}
	while (stack_b)
	{
		tmp = stack_b->next;
		free(stack_b);
		stack_b = tmp;
	}
}

void		del_first_elem_in_stack(t_stack **stack)
{
	t_stack *del;
	t_stack *end;

	end = (*stack)->next;
	del = *stack;
	if ((*stack)->number == (*stack)->next->number)
	{
		free(stack);
		stack = NULL;
	}
	*stack = (*stack)->previous;
	(*stack)->next = del->next;
	end->previous = *stack;
	del->next = NULL;
	del->previous = NULL;
	free(del);
	del = NULL;
}

void		add_num_in_stack(int number, t_stack *stack)
{
	t_stack	*head;
	t_stack	*new_elem;
	t_stack	*end;

	head = stack;
	if (!(new_elem = (t_stack *)malloc(sizeof(t_stack))))
		return ;
	new_elem->number = number;
	end = head->previous;
	end->next = new_elem;
	new_elem->next = head;
	new_elem->previous = end;
	head->previous = new_elem;
}

t_stack		*init_stack(int number)
{
	t_stack	*stack;

	if (!(stack = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	stack->number = number;
	stack->next = stack;
	stack->previous = stack;
	return (stack);
}
