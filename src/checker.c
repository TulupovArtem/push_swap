/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:03:13 by idunaver          #+#    #+#             */
/*   Updated: 2019/07/23 11:44:58 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// проверка на то, отсортирован ли в итоге массив
static void		sort_or_not_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *tmp;

	tmp = stack_a;
	if (stack_b)
		return ;
	while (tmp->next->number != stack_a->number)
	{
		if (tmp->number < tmp->next->number)
			tmp = tmp->next;
		else
		{
			ft_putendl("unsorted");
			return ;
		}
	}
	ft_putendl("sorted");
}

// проверка аргументов на разные числа (разные числа нельзя)
static int		different_numbers(char **number, int count)
{
	int		n[count];
	char	**tmp;
	int		i;
	int		j;
	int		count_tmp;

	i = 0;
	j = 0;
	count_tmp = count;
	tmp = number;
	while (count)
		n[--count] = ft_atoi(*(tmp++));
	while (i < count_tmp)
	{
		if (j + 1 < count_tmp && n[i] != n[j + 1])
			j++;
		else if (j + 1 < count_tmp && n[i] == n[j + 1])
			return (0);
		else
			j = ++i;
	}
	return (1);
}

// проверка на то, числа ли аргументы. Переходит в проверку на разные числа.
static int		check_number(char **number, int ac)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ac - 1)
	{
		if (ft_atoi(number[i]) < 0)
			j++;
		while (number[i][j])
		{
			if (!(number[i][j] >= '0' && number[i][j] <= '9'))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (different_numbers(number, i));
}

// парс флагов
static void			input(t_stack *stack_a, t_stack *stack_b)
{
	char *line;

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
			stack_a = init_stack(ft_atoi(*av));
			while (--ac != -1 && *(++av))
				add_num_in_stack(ft_atoi(*av), stack_a);
			input(stack_a, stack_b);
		}
		else
			ft_putendl("error: invalid input");
	}
	return (0);
}
