/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_quot_arr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 15:10:17 by idunaver          #+#    #+#             */
/*   Updated: 2019/09/03 15:19:38 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long		*fill_quoted_array(char *numbers, int count)
{
	long long	*n;
	int			i;
	int			j;
	int			ind;

	ind = 0;
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
			n[ind++] = ft_atoll(&numbers[j]);
		while ((numbers[i] >= '0' && numbers[i] <=
		'9' && numbers[i] != '\0') || numbers[i] == '-')
			i++;
	}
	return (n);
}
