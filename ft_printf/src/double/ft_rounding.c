/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rounding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramory-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 20:08:08 by idunaver          #+#    #+#             */
/*   Updated: 2019/06/15 15:33:24 by ramory-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_replace_num_round(int check, long long accuracy,
char *result)
{
	while (accuracy)
	{
		accuracy--;
		check = result[accuracy] - '0';
		check++;
		if (check > 9)
		{
			result[accuracy] = 0 + '0';
			check = result[accuracy] - '0';
		}
		else if (check != 9)
		{
			result[accuracy] = check + '0';
			break ;
		}
	}
	return (result);
}

char		*ft_if_five_in_fractional(char *result,
int check, long long accuracy)
{
	int			check_null;

	check_null = accuracy + 1;
	while (result[check_null])
	{
		if (result[check_null] != '0')
			break ;
		check_null++;
	}
	if (result[check_null])
		result = ft_replace_num_round(check, accuracy, result);
	return (result);
}

char		*ft_rounding_fraction(char *result, long long accuracy)
{
	int			check;
	char		*tmp;
	long long	accuracy_tmp;

	check = 0;
	tmp = result;
	accuracy_tmp = accuracy + 1;
	while (*tmp++)
		accuracy_tmp--;
	if (accuracy_tmp < 0)
	{
		check = result[accuracy] - '0';
		if (check == 5)
			result = ft_if_five_in_fractional(result, check, accuracy);
		else if (check > 5)
			result = ft_replace_num_round(check, accuracy, result);
	}
	return (result);
}

char		*ft_rounding(char *result, long long accuracy)
{
	char	*tmp;
	int		before;
	int		after;
	int		count;
	int		check;

	check = 0;
	count = 0;
	tmp = result;
	while (*tmp != '.')
	{
		tmp++;
		count++;
	}
	tmp++;
	before = *tmp - '0';
	tmp = ft_rounding_fraction(tmp, accuracy);
	after = *tmp - '0';
	if (before > after || (after >= 5 && accuracy == 0))
	{
		check = result[count] - '0';
		result = ft_replace_num_round(check, count, result);
	}
	return (result);
}
