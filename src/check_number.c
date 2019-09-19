/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 16:20:36 by idunaver          #+#    #+#             */
/*   Updated: 2019/09/19 19:49:15 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		fill_stack_error(t_stack **stack_a, char **av)
{
	ft_putendl("Error");
	free_stacks(*stack_a, NULL);
	free_double_arr(av);
}

int			check_double_overloaded(char *number)
{
	if (ft_strlen(number) > 10)
		return (0);
	else
		return (1);
}

static int	different_numbers_helper(int i, int count_tmp, int j, int **tmp)
{
	int *n;

	n = *tmp;
	while (i < count_tmp)
	{
		if (j + 1 < count_tmp && n[i] != n[j + 1])
			j++;
		else if (j + 1 < count_tmp && n[i] == n[j + 1])
		{
			free(n);
			return (0);
		}
		else
			j = ++i;
	}
	return (1);
}

static int	different_numbers(char **number, int count)
{
	int		*n;
	char	**tmp;
	int		i;
	int		j;
	int		count_tmp;

	i = 0;
	j = 0;
	count_tmp = count;
	tmp = number;
	if (!(n = (int *)malloc(count * sizeof(int))))
		return (0);
	while (count)
		n[--count] = ft_atoll(*(tmp++));
	if (different_numbers_helper(i, count_tmp, j, &n) == 0)
		return (0);
	free(n);
	return (1);
}

int			check_number(char **number, int ac)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < ac - 1)
	{
		if (ft_atoll(number[i]) < 0 || (ft_strchr(number[i], '+')
		&& ft_strchr(number[i], '0')) || (ft_strchr(number[i], '-')
		&& ft_strchr(number[i], '0')))
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
