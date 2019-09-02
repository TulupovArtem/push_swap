/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quoted_argument.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:04:18 by idunaver          #+#    #+#             */
/*   Updated: 2019/09/02 17:36:03 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	checked_array(char *av)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = av;
	while (tmp[i])
	{
		if (tmp[i] == '-' && tmp[i + 1] != '\0')
		{
			i++;
			if (tmp[i] == '-')
			{
				ft_putendl("Error");
				return (0);
			}
		}
		if (((tmp[i] < '0' && tmp[i] > '9') && tmp[i] != ' ' && tmp[i] != '-'))
		{
			ft_putendl("Error");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	counting_quoted_numbers(char *av)
{
	int		i;
	int		j;
	int		count;
	char	*tmp;

	tmp = av;
	count = 0;
	i = 0;
	j = 0;
	while (tmp[i])
	{
		while (tmp[i] == ' ' && tmp[i] != '\0')
			i++;
		j = i;
		if (tmp[i] != ' ' && tmp[i] != '\0')
			count++;
		if (ft_atoll(&tmp[j]) < 0)
			i++;
		while (tmp[i] >= '0' && tmp[i] <= '9' && tmp[i] != '\0')
			i++;
	}
	if (count == 1)
		ft_putendl("Error");
	return (count);
}

static int	diff_or_not_diff(long long *n, int count)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < count)
	{
		if (j + 1 < count && n[i] != n[j + 1])
			j++;
		else if (j + 1 < count && n[i] == n[j + 1])
		{
			free(n);
			return (0);
		}
		else
			j = ++i;
	}
	free(n);
	return (1);
}

static int	diff_quoted_num(char *numbers, int count)
{
	long long 	*n;
	int		i;
	int		j;
	int		count_tmp;

	i = 0;
	j = 0;
	count_tmp = count;
	n = fill_quoted_array(numbers, count);
	if (diff_or_not_diff(n, count_tmp) == 0)
		return (0);
	return (1);
}

int	quoted_argument(char **av, t_stack **stack_a, t_stack **stack_b)
{
	int		count;
	long long		*n;

	count = 0;
	if (checked_array(*av) == 0 || counting_quoted_numbers(*av) <= 1)
		return (1);
	count = counting_quoted_numbers(*av);
	if (diff_quoted_num(*av, count) == 0)
	{
		ft_putendl("Error");
		return (1);
	}
	n = fill_quoted_array(*av, count);
	back_to_the_checker(n, stack_a, stack_b, count);
	return (0);
}