/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_list_op.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 19:15:17 by idunaver          #+#    #+#             */
/*   Updated: 2019/08/30 20:38:37 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_count_op	*init_list_op(int number, int op_a, int op_b)
{
	t_count_op	*oper;

	if (!(oper = (t_count_op *)malloc(sizeof(t_count_op))))
		return (NULL);
	oper->number = number;
	if (op_a < 0)
	{
		oper->rev_rot_a = 1;
		oper->op_a = op_a * (-1);
	}
	else
	{
		oper->rev_rot_a = 0;
		oper->op_a = op_a;
	}
	oper->op_b = op_b;
	oper->sum_oper = oper->op_a + oper->op_b;
	oper->next = NULL;
	oper->rev_rot_b = 0;
	return (oper);
}

void		add_elem_in_list_op(int number, int op_a,
int op_b, t_count_op **oper)
{
	t_count_op *new_elem;
	t_count_op *tmp;

	tmp = *oper;
	if (!(new_elem = (t_count_op *)malloc(sizeof(t_count_op))))
		return ;
	while (tmp->next != NULL)
		tmp = tmp->next;
	new_elem->number = number;
	if (op_a < 0)
	{
		new_elem->rev_rot_a = 1;
		new_elem->op_a = op_a * (-1);
	}
	else
	{
		new_elem->rev_rot_a = 0;
		new_elem->op_a = op_a;
	}
	new_elem->op_b = op_b;
	new_elem->sum_oper = new_elem->op_a + new_elem->op_b;
	tmp->next = new_elem;
	new_elem->next = NULL;
	new_elem->rev_rot_b = 0;
}

void		free_list_op(t_count_op **oper)
{
	t_count_op	*tmp;

	tmp = NULL;
	while (*oper)
	{
		tmp = (*oper)->next;
		free(*oper);
		*oper = NULL;
		*oper = tmp;
	}
}
