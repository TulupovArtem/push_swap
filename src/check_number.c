/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 16:20:36 by idunaver          #+#    #+#             */
/*   Updated: 2019/09/02 15:19:46 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	while (i < count_tmp)
	{
		if (j + 1 < count_tmp && n[i] != n[j + 1])
			j++;
		else if (j + 1 < count_tmp && n[i] == n[j + 1])
			return (0);
		else
			j = ++i;
	}
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
		if (ft_atoll(number[i]) < 0)
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
