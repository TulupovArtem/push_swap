/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:06:43 by idunaver          #+#    #+#             */
/*   Updated: 2019/07/22 17:16:08 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>

typedef struct		s_stack
{
	int				number;
	struct s_stack	*next;
	struct s_stack	*previous;
}					t_stack;

/* work_with_stack.c */
void				free_stacks(t_stack *stack_a, t_stack *stack_b);
void				del_first_elem_in_stack(t_stack *stack);
void				add_num_in_stack(int number, t_stack *stack);
t_stack				*init_stack(int number);

/* what_operation.c */
void				what_reverse_rotate(char **line, t_stack *stack_a, t_stack *stack_b);
void				what_rotate(char **line, t_stack *stack_a, t_stack *stack_b);
void				what_push(char **line, t_stack *stack_a, t_stack *stack_b);
void				what_swap(char **line, t_stack *stack_a, t_stack *stack_b);


/* swap.c */
void				swap(t_stack *stack);

/* push.c */
void				push_a(t_stack *stack_a, t_stack *stack_b);
void				push_b(t_stack *stack_a, t_stack *stack_b);

/* rotate.c */
void				rotate(t_stack *stack);

/* reverse_rotate.c */
void				reverse_rotate(t_stack *stack);

#endif
