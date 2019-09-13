/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 21:46:42 by idunaver          #+#    #+#             */
/*   Updated: 2019/09/13 19:58:53 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	len_a_for_cell(int len_a, t_stack *stack_a)
{
	len_a = count_numbers_in_n(stack_a->number);
	if (stack_a->number < 0)
		len_a++;
	return (len_a);
}

static int	len_b_for_cell(int len_b, t_stack *stack_b)
{
	len_b = count_numbers_in_n(stack_b->number);
	if (stack_b->number < 0)
		len_b++;
	return (len_b);
}

static void	cell_one(int width, t_stack *stack_a, int len_a)
{
	int tmp;

	tmp = 0;
	printf("| ");
	tmp = (width - len_a - 3) / 2;
	while (tmp--)
		printf(" ");
	if (stack_a)
		printf("\033[32mfff\033[m%lld", stack_a->number);
	tmp = (width - len_a - 2) / 2;
	while (tmp--)
		printf(" ");
}

static void	cell_two(int width, t_stack *stack_b, int len_b)
{
	int tmp;

	tmp = 0;
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

void		cell(int width, t_stack *stack_a, t_stack *stack_b)
{
	int tmp;
	int len_a;
	int len_b;

	len_a = 0;
	len_b = 0;
	tmp = 0;
	if (stack_a)
		len_a = len_a_for_cell(len_a, stack_a);
	if (stack_b)
		len_b = len_b_for_cell(len_b, stack_b);
	cell_one(width, stack_a, len_a);
	printf(" | ");
	cell_two(width, stack_b, len_b);
}
