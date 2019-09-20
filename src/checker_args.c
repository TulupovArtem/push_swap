/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 13:47:21 by idunaver          #+#    #+#             */
/*   Updated: 2019/09/20 19:41:25 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	input_with_visual(t_stack **stack_a, t_stack **stack_b,
char **new_av, int len_arr)
{
	len_arr--;
	if (!(*stack_a = fill_stack(stack_a, new_av, len_arr, 1)))
		return (0);
	input(stack_a, stack_b, 1);
	return (1);
}

static int	input_without_visual(t_stack **stack_a, t_stack **stack_b,
char **new_av, int len_arr)
{
	if (!(*stack_a = fill_stack(stack_a, new_av, len_arr, 0)))
		return (0);
	input(stack_a, stack_b, 0);
	return (1);
}

static int	input_with_visual_color(t_stack **stack_a, t_stack **stack_b,
char **new_av, int len_arr)
{
	len_arr -= 2;
	if (!(*stack_a = fill_stack(stack_a, new_av, len_arr, 2)))
		return (0);
	input(stack_a, stack_b, 2);
	return (1);
}

static int	input_with_param(t_stack **stack_a, t_stack **stack_b,
char **new_av, int len_arr)
{
	if (len_arr > 2 && ft_strcmp(*(new_av + 1), "-c") == 0)
	{
		if (input_with_visual_color(stack_a, stack_b, new_av, len_arr) == 0)
			return (0);
	}
	else if (len_arr >= 2)
	{
		if (input_with_visual(stack_a, stack_b, new_av, len_arr) == 0)
			return (0);
	}
	return (1);
}

void		checker(char **av, t_stack **stack_a, t_stack **stack_b)
{
	char	**new_av;
	int		len_arr;

	len_arr = 0;
	new_av = create_new_av(av);
	len_arr = len_double_arr(new_av);
	if ((len_arr == 2 && ft_strcmp(*new_av, "-v") == 0) ||
	(len_arr == 3 && ft_strcmp(*(new_av + 1), "-c") == 0))
		ft_putendl("Error");
	else if (len_arr != 1 && ft_strcmp(*new_av, "-v") == 0)
	{
		if (input_with_param(stack_a, stack_b, new_av, len_arr) == 0)
			return ;
	}
	else
	{
		if (input_without_visual(stack_a, stack_b, new_av, len_arr) == 0)
			return ;
	}
	free_stacks(*stack_a, *stack_b);
	free_double_arr(new_av);
}
