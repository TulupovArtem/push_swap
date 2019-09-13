/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_algorythm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 14:38:25 by idunaver          #+#    #+#             */
/*   Updated: 2019/09/13 19:56:16 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		sort_or_not_sort(t_stack *stack_a, t_stack *stack_b, int visual)
{
	t_stack	*tmp;

	tmp = stack_a;
	visual_stacks(&stack_a, &stack_b, visual);
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

static int		rotate_or_reverse_rotate(t_stack **stack_a,
t_stack **stack_b, char *line)
{
	if (ft_strlen(line) > 2 && ft_strchr(line + 1, 'r'))
	{
		if (what_reverse_rotate(&line, stack_a, stack_b) == 0)
			return (0);
	}
	else
	{
		if (what_rotate(&line, stack_a, stack_b) == 0)
			return (0);
	}
	return (1);
}

static int		gnl_plus_input(t_stack **stack_a,
t_stack **stack_b, char *line)
{
	if (ft_strchr(line, 's'))
	{
		if (what_swap(&line, stack_a, stack_b) == 0)
			return (0);
	}
	else if (ft_strchr(line, 'p'))
	{
		if (what_push(&line, stack_a, stack_b) == 0)
			return (0);
	}
	else if (ft_strchr(line, 'r'))
	{
		if (rotate_or_reverse_rotate(stack_a, stack_b, line) == 0)
			return (0);
	}
	else
		return (0);
	return (1);
}

void			input(t_stack **stack_a, t_stack **stack_b, int visual)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (gnl_plus_input(stack_a, stack_b, line) == 0)
		{
			ft_putendl("Error");
			return ;
		}
		else if (*line == '\0')
			break ;
		if (visual == 1)
			visual_stacks(stack_a, stack_b, visual);
	}
	sort_or_not_sort(*stack_a, *stack_b, visual);
}
