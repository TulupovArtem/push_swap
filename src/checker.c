/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:03:13 by idunaver          #+#    #+#             */
/*   Updated: 2019/07/18 15:52:59 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void add_num_in_stack(int number, t_stack *stack)
{
    t_stack *tmp;

    tmp = stack;
    while (tmp->next)
        tmp = tmp->next;
    if(!(tmp->next = (t_stack *)malloc(sizeof(t_stack))))
        return ;
    tmp->next->number = number;
    tmp->next->next = NULL;
}

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
    int i;
    int j;

    i = 0;
    j = 0;
    while (number[i])
    {
        if (ft_atoi(number[i]) < 0)
            j++;
        while (number[i][j])
        {
            if (!(number[i][j] >= 48 && number[i][j] <= 57))
                return (0);
                j++;
        }
        j = 0;
        i++;
    }
    return (1);
}

int main(int ac, char **av)
{
    t_stack *stack = NULL;

    if (ac == 1)
        return (0);
    else
    {
        if (check_number(av) != 0)
        {
            stack = init_stack(ft_atoi(*(av++)));
            while(*(++av))
                add_num_in_stack(ft_atoi(*av), stack);
        }
        else
            ft_putendl("error");
    }
    return (0);
}