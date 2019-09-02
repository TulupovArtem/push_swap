/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_quot_arr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 15:10:17 by idunaver          #+#    #+#             */
/*   Updated: 2019/09/02 17:35:04 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long		*fill_quoted_array(char *numbers, int count)
{
	long long	*n;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!(n = (long long *)malloc(count * sizeof(long long))))
        return (0);
	while (numbers[i])
	{
		while (numbers[i] == ' ' && numbers[i] != '\0')
			i++;
		j = i;
		if (numbers[i] != ' ' && numbers[i] != '\0')
			n[--count] = ft_atoll(&numbers[j]);
		while ((numbers[i] >= '0' && numbers[i] <=
		'9' && numbers[i] != '\0') || numbers[i] == '-')
			i++;
	}
	return (n);
}


void	back_to_the_checker(long long *n, t_stack **stack_a, t_stack **stack_b, int count)
{
	if (!(*n > INT_MAX) && !(*n < INT_MIN))
		{
			stack_a = init_stack(*n);
			while (count-- && ++n)
			{
				if (!(*n > INT_MAX) && !(*n < INT_MIN))
					add_num_in_stack(*n, *stack_a);
				else
				{
					ft_putendl("Error");
					return (0);
				}
			}
			input(*stack_a, *stack_b);
			free_stacks(*stack_a, *stack_b);
		}
		else
			ft_putendl("Error");
}