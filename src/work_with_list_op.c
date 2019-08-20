/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_list_op.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 19:15:17 by idunaver          #+#    #+#             */
/*   Updated: 2019/08/20 15:02:43 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_count_op	*init_list_op(int number, int op_a, int op_b)
{
	t_count_op	*oper;

	if (!(oper = (t_count_op *)malloc(sizeof(t_count_op))))
		return (NULL);
	oper->number = number;
	oper->op_a = op_a;
	oper->op_b = op_b;
	oper->sum_oper = op_a + op_b;
	oper->next = NULL;
	oper->previous = NULL;
	oper->rev_rot_b = 0;
	return (oper);
}

void		add_elem_in_list_op(int number, int op_a,
int op_b, t_count_op *oper)
{
	t_count_op *new_elem;

	if (!(new_elem = (t_count_op *)malloc(sizeof(t_count_op))))
		return ;
	new_elem->number = number;
	new_elem->op_a = op_a;
	new_elem->op_b = op_b;
	new_elem->sum_oper = op_a + op_b;
	oper->next = new_elem;
	new_elem->previous = oper;
	new_elem->next = NULL;
	new_elem->rev_rot_b = 0;
}

void		free_list_op(t_count_op *oper)
{
	t_count_op	*tmp;

	tmp = NULL;
	while (oper)
	{
		tmp = oper->next;
		free(oper);
		oper = NULL;
		oper = tmp;
	}
}
