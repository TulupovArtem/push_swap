/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:03:13 by idunaver          #+#    #+#             */
/*   Updated: 2019/07/08 15:59:24 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack *init_stack(int number)
{
    t_stack *stack;

    if (!(stack = (t_stack *)malloc(sizeof(t_stack))))
        return (NULL);
    stack->number = number;
    stack->next = NULL;
    return (stack);
}

static int  check_number(char **number)
{
    while (*number++)
        while (**number++)
            if (!(**number >= 48 && **number <= 57))
                return (0);
    return (1);
}

int main(int ac, char **av)
{
    t_stack *stack = NULL;

    if (ac == 0)
        return (0);
    else
        printf("%d\n", check_number(av));
    return (0);
}