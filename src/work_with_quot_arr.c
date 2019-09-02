/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_quot_arr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 15:10:17 by idunaver          #+#    #+#             */
/*   Updated: 2019/09/02 17:19:09 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*fill_quoted_array(char *numbers, int count)
{
	int *n;
	int i;
	int j;

	i = 0;
	j = 0;
	if (!(n = (int *)malloc(count * sizeof(int))))
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


void	*back_to_the_checker(int *n, t_stack **stack_a, t_stack **stack_b, int count)
{
	if (!(ft_atoll(*n) > INT_MAX) && !(ft_atoll(*n) < INT_MIN))
		{
			stack_a = init_stack(ft_atoll(*n));
			while (count-- && ++n)
				add_num_in_stack(ft_atoll(*n), stack_a);
			input(stack_a, stack_b);
		}
		else
			ft_putendl("Error");
}