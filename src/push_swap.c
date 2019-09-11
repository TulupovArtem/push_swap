/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:02:59 by idunaver          #+#    #+#             */
/*   Updated: 2019/09/11 22:16:37 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(int ac, char **av, t_stack **stack_a, t_stack **stack_b)
{
	char	**new_av;
	int		len_arr;
	int 	arg;

	arg = ac - 1;
	len_arr = 0;
	new_av = create_new_av(av);
	len_arr = len_double_arr(new_av);
	if (!(*stack_a = fill_stack(stack_a, new_av, len_arr)))
			return ;
	sort_numbers(stack_a, stack_b, arg);
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
		push_swap(ac, av, &stack_a, &stack_b);
	return (0);
}
