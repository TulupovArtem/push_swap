/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:03:13 by idunaver          #+#    #+#             */
/*   Updated: 2019/08/27 18:44:32 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		sort_or_not_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp;

	tmp = stack_a;
	if (stack_b)
	{
		ft_putendl("KO");
		return ;
	}
	while (tmp->previous->number != stack_a->number)
	{
		if (tmp->number > tmp->previous->number)
			tmp = tmp->previous;
		else
		{
			ft_putendl("KO");
			return ;
		}
	}
	ft_putendl("OK");
}

static void		input(t_stack *stack_a, t_stack *stack_b)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (*line == 's')
			what_swap(&line, &stack_a, &stack_b);
		else if (*line == 'p')
			what_push(&line, &stack_a, &stack_b);
		else if (*(line++) == 'r')
		{
			if (*(line) == 'r')
				what_reverse_rotate(&line, &stack_a, &stack_b);
			else
				what_rotate(&line, &stack_a, &stack_b);
		}
		else
		{
			sort_or_not_sort(stack_a, stack_b);
			return ;
		}
	}
	sort_or_not_sort(stack_a, stack_b);
}

int				main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack *stack_b;

	stack_b = NULL;
	stack_a = NULL;
	if (ac == 1)
		return (0);
	else
	{
		if (check_number(++av, ac) == 1)
		{
			ac--;
			stack_a = init_stack(ft_atoll(*av));
			while (--ac != -1 && *(++av))
				add_num_in_stack(ft_atoll(*av), stack_a);
			input(stack_a->previous, stack_b);
		}
		else
			ft_putendl("Error");
	}
	return (0);
}
