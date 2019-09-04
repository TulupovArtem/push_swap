/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:03:13 by idunaver          #+#    #+#             */
/*   Updated: 2019/09/04 17:15:09 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		norm_count_arguments(t_stack **stack_a, t_stack **stack_b,
char **av, int ac)
{
	if (check_number(++av, ac) == 1 && !(ft_atoll(*av)
	> INT_MAX) && !(ft_atoll(*av) < INT_MIN))
	{
		ac--;
		*stack_a = init_stack(ft_atoll(*av));
		while (--ac != -1 && *(++av))
		{
			if (!(ft_atoll(*av) > INT_MAX) && !(ft_atoll(*av) < INT_MIN))
				add_num_in_stack(ft_atoll(*av), *stack_a);
			else
			{
				ft_putendl("Error");
				return ;
			}
		}
		input(stack_a, stack_b);
		free_stacks(*stack_a, *stack_b);
	}
	else
		ft_putendl("Error");
}

int				main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack *stack_b;

	stack_b = NULL;
	stack_a = NULL;
	if (ac == 1)
		return (0);
	else if (ac == 2)
		return (quoted_argument(++av, &stack_a, &stack_b, 1));
	else
		norm_count_arguments(&stack_a, &stack_b, av, ac);
	return (0);
}
