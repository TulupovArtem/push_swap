/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 20:33:51 by idunaver          #+#    #+#             */
/*   Updated: 2019/09/13 20:46:08 by idunaver         ###   ########.fr       */
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
	ft_printf("| ");
	tmp = (width - len_a - 3) / 2;
	while (tmp--)
		ft_printf(" ");
	if (stack_a)
		ft_printf("\033[31m%lld\033[m", stack_a->number);
	tmp = (width - len_a - 2) / 2;
	while (tmp--)
		ft_printf(" ");
}

static void	cell_two(int width, t_stack *stack_b, int len_b)
{
	int tmp;

	tmp = 0;
	tmp = (width - len_b - 2) / 2;
	while (tmp--)
		ft_printf(" ");
	if (stack_b)
		ft_printf("\033[32m%lld\033[m", stack_b->number);
	tmp = (width - len_b - 3) / 2;
	while (tmp--)
		ft_printf(" ");
	ft_printf(" |\n");
}

void		cell_color(int width, t_stack *stack_a, t_stack *stack_b)
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
	ft_printf(" | ");
	cell_two(width, stack_b, len_b);
}
