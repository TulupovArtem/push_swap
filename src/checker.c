/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:03:13 by idunaver          #+#    #+#             */
/*   Updated: 2019/07/18 17:52:42 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void add_num_in_stack(int number, t_stack *stack)
{
    t_stack *tmp;
    // t_stack *prev;

    tmp = stack;
    while (tmp->next)
        tmp = tmp->next;
    if(!(tmp->next = (t_stack *)malloc(sizeof(t_stack))))
        return ;
    // prev = tmp;
    tmp->next->number = number;
    tmp->next->next = NULL;
    tmp->next->previous = tmp;
}

static t_stack *init_stack(int number)
{
    t_stack *stack;

    if (!(stack = (t_stack *)malloc(sizeof(t_stack))))
        return (NULL);
    stack->number = number;
    stack->next = NULL;
    stack->previous = NULL;
    return (stack);
}

static int  different_numbers(char **number, int count)
{
    int n[count];
    char **tmp;
    int i;
    int j;
    int count_tmp;
    
    i = 0;
    j = 0;
    count_tmp = count;
    tmp = number;
    while (*tmp)
        n[--count] = ft_atoi(*(tmp++));
    while (i <= count_tmp - 1)
    {
        if (j + 1 <= count_tmp && n[i] != n[j + 1])
            j++;
        else if (j + 1 <= count_tmp && n[i] == n[j + 1])
            return (0);
        else
            j = ++i;
    }
    return (1);
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
    return (different_numbers(number, i));
}

int main(int ac, char **av)
{
    t_stack *stack_a = NULL;

    if (ac == 1)
        return (0);
    else
    {
        if (check_number(++av) == 1)
        {
            ft_putendl("vse verno, molodec");
            stack_a = init_stack(ft_atoi(*(av++)));
            while(*(++av))
                add_num_in_stack(ft_atoi(*av), stack_a);
        }
        else
            ft_putendl("error");
    }
    return (0);
}