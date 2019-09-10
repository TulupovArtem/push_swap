/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_algorythm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 14:38:25 by idunaver          #+#    #+#             */
/*   Updated: 2019/09/10 20:44:09 by idunaver         ###   ########.fr       */
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
	while (tmp->next->number != stack_a->number)
	{
		if (tmp->number < tmp->next->number)
			tmp = tmp->next;
		else
		{
			ft_putendl("KO");
			return ;
		}
	}
	ft_putendl("OK");
}

void			input(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (ft_strchr(line, 's'))
			what_swap(&line, stack_a, stack_b);
		else if (ft_strchr(line, 'p'))
			what_push(&line, stack_a, stack_b);
		else if (ft_strchr(line, 'r'))
		{
			if (ft_strlen(line) > 2 && ft_strchr(line + 1, 'r'))
				what_reverse_rotate(&line, stack_a, stack_b);
			else
				what_rotate(&line, stack_a, stack_b);
		}
		else if (*line == '\0')
			break ;
		else
		{
			ft_putendl("Error");
			return ;
		}
	}
	sort_or_not_sort(*stack_a, *stack_b);
}
