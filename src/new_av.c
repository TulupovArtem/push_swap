/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_av.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:24:59 by idunaver          #+#    #+#             */
/*   Updated: 2019/09/16 15:32:06 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		len_double_arr(char **arr)
{
	int		count;
	char	**tmp;

	tmp = arr;
	count = 1;
	while (*tmp++)
		count++;
	return (count);
}

t_stack	*fill_stack(t_stack **stack_a, char **av, int ac)
{
	if (check_number(av, ac) == 1 && !(ft_atoll(*av)
	> INT_MAX) && !(ft_atoll(*av) < INT_MIN) &&
	check_double_overloaded(*av) == 1)
	{
		ac--;
		*stack_a = init_stack(ft_atoll(*av));
		while (--ac != -1 && *(++av))
		{
			if (!(ft_atoll(*av) > INT_MAX) && !(ft_atoll(*av) < INT_MIN))
				add_num_in_stack(ft_atoll(*av), *stack_a);
			else
			{
				ft_putendl("Error");
				free_double_arr(av);
				exit (EXIT_FAILURE);
			}
		}
		return (*stack_a);
	}
	else
		ft_putendl("Error");
	free_double_arr(av);
	exit (EXIT_FAILURE);
}

int		count_elems(char **av)
{
	int count;
	int i;
	int j;

	i = 1;
	j = 0;
	count = 0;
	while (av[i] != NULL)
	{
		while (av[i][j] != '\0')
		{
			while (av[i][j] == ' ' && av[i][j] != '\0')
				j++;
			while (av[i][j] != ' ' && av[i][j] != '\0')
				j++;
			count++;
			while (av[i][j] == ' ' && av[i][j] != '\0')
				j++;
		}
		j = 0;
		i++;
	}
	return (count);
}

void	free_double_arr(char **double_arr)
{
	char	**tmp;
	int		len;

	len = 0;
	tmp = double_arr;
	if (double_arr == NULL)
		exit (EXIT_FAILURE);
	while (*tmp++)
		len++;
	len--;
	while (len != -1)
	{
		free(double_arr[len]);
		double_arr[len] = NULL;
		len--;
	}
	free(double_arr);
	double_arr = NULL;
}

char	**create_new_av(char **av)
{
	int		i;
	int		elems;
	char	**new_av;
	char	**elem;
	char	**tmp;

	i = 0;
	tmp = NULL;
	elems = count_elems(av);
	if (!(new_av = (char **)malloc((elems + 1) * sizeof(char *))))
		exit (EXIT_FAILURE);
	while (i != elems)
	{
		elem = ft_strsplit(*(++av), ' ');
		tmp = elem;
		while (*tmp)
		{
			new_av[i] = ft_strdup(*tmp);
			tmp++;
			i++;
		}
		free_double_arr(elem);
	}
	new_av[elems] = NULL;
	return (new_av);
}
