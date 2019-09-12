/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:03:13 by idunaver          #+#    #+#             */
/*   Updated: 2019/09/12 21:04:32 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	checker(char **av, t_stack **stack_a, t_stack **stack_b)
{
	char	**new_av;
	int		len_arr;

	len_arr = 0;
	new_av = create_new_av(av);
	len_arr = len_double_arr(new_av);
	if (ft_strcmp(*new_av, "-v") == 0 && len_arr != 1)
	{
		if (!(*stack_a = fill_stack(stack_a, new_av + 1, --len_arr)))
			return ;
		input(stack_a, stack_b, 1);
	}
	else
	{
		if (!(*stack_a = fill_stack(stack_a, new_av, len_arr)))
			return ;
		input(stack_a, stack_b, 0);
	}
	free_stacks(*stack_a, *stack_b);
	free_double_arr(new_av);
}

int			main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack *stack_b;

	stack_b = NULL;
	stack_a = NULL;
	if (ac == 1)
		return (0);
	else
		checker(av, &stack_a, &stack_b);
	return (0);
}
