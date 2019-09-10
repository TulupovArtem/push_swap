/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:02:59 by idunaver          #+#    #+#             */
/*   Updated: 2019/09/10 20:45:12 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	norm_count_arguments(t_stack **stack_a, t_stack **stack_b,
char **av, int ac)
{
	int arg;

	arg = ac - 1;
	if (check_number(av, ac) == 1 && !(ft_atoll(*av)
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
		sort_numbers(stack_a, stack_b, arg);
		free_stacks(*stack_a, *stack_b);
	}
	else
		ft_putendl("Error");
}

int			main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack *stack_b;
	char	**new_av;
	char	**tmp;

	stack_b = NULL;
	stack_a = NULL;
	if (ac == 1)
		return (0);
	else if (ac == 2)
	{
		new_av = ft_strsplit(*(++av), ' ');
		tmp = new_av;
		ac = 1;
		while (*(tmp++) != NULL)
			ac++;
		norm_count_arguments(&stack_a, &stack_b, new_av, ac);
	}
	else
		norm_count_arguments(&stack_a, &stack_b, ++av, ac);
	return (0);
}
