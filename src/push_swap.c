/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:02:59 by idunaver          #+#    #+#             */
/*   Updated: 2019/07/31 20:32:57 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	all_numbers_in_b(t_stack *stack_a, t_stack *stack_b)
{

}

int		main(int ac, char **av)
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
			
		}
		else
			ft_putendl("Error");
	return (0);
}
