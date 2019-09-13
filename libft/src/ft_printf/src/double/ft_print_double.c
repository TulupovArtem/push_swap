/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramory-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 20:02:12 by idunaver          #+#    #+#             */
/*   Updated: 2019/06/15 18:54:42 by ramory-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printfractional(t_printf *data, char *result, t_buffer *bf)
{
	if (data->accuracy == 0)
		return ;
	else
	{
		bf->buffer[bf->s] = *result;
		bf->s++;
		result++;
		ft_check_buffer(data, bf);
		while (*result && data->accuracy)
		{
			bf->buffer[bf->s] = *result;
			bf->s++;
			result++;
			data->accuracy--;
			ft_check_buffer(data, bf);
		}
		while (data->accuracy > 0)
		{
			bf->buffer[bf->s] = '0';
			bf->s++;
			result++;
			data->accuracy--;
			ft_check_buffer(data, bf);
		}
	}
}

void		ft_printlongdouble(char *result, t_printf *data, int sign,
t_buffer *bf)
{
	int before;
	int after;

	before = *result - '0';
	result = ft_rounding(result, data->accuracy);
	after = *result - '0';
	if (after == 0 && before != 0)
		result = ft_strjoin("1", result);
	if (sign == 1)
	{
		bf->buffer[bf->s] = '-';
		bf->s++;
		ft_check_buffer(data, bf);
	}
	while (*result != '.')
	{
		bf->buffer[bf->s] = *result;
		bf->s++;
		result++;
		ft_check_buffer(data, bf);
	}
	ft_printfractional(data, result, bf);
}
