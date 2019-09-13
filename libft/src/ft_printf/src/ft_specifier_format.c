/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramory-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 14:02:49 by ramory-l          #+#    #+#             */
/*   Updated: 2019/06/15 16:15:20 by ramory-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_check_flag(const char *format, t_printf *data)
{
	if (*format == '-')
		data->flags |= FLAG_MINUS;
	if (*format == '+')
		data->flags |= FLAG_PLUS;
	if (*format == ' ')
		data->flags |= FLAG_SPACE;
	if (*format == '#')
		data->flags |= FLAG_OCT;
	if (*format == '0' && !ft_isdigit(*(format - 1)) && *(format - 1) != '.')
		data->flags |= FLAG_ZERO;
}

static void	ft_check_width(int *i, const char *format, t_printf *data)
{
	if (format[*i] >= '1' && format[*i] <= '9' && format[*i - 1] != '.' &&
		data->width == 0)
	{
		data->width = ft_atoi(&format[*i]);
		while (ft_isdigit(format[*i]))
			(*i)++;
		(*i)--;
	}
}

static void	ft_check_acc(const char *format, t_printf *data)
{
	if (*format == '.')
	{
		data->acc = 1;
		if (*(format + 1) >= '1' && *(format + 1) <= '9')
			data->accuracy = ft_atoi(format + 1);
	}
}

static void	ft_check_size(t_printf *data)
{
	if (data->count_l)
	{
		data->size |= SIZE_LLL;
		return ;
	}
	if (data->l_count)
	{
		if (data->l_count % 2)
			data->size |= SIZE_L;
		else
			data->size |= SIZE_LL;
		return ;
	}
	if (data->h_count)
	{
		if (data->h_count % 2)
			data->size |= SIZE_H;
		else
			data->size |= SIZE_HH;
	}
}

int			ft_specifier_format(const char *format, t_printf *data)
{
	int	i;
	int index;

	i = 0;
	index = 0;
	while (format[++i])
	{
		if (type(format[i]))
		{
			index = i;
			break ;
		}
		ft_check_flag(&format[i], data);
		ft_check_width(&i, format, data);
		ft_check_acc(&format[i], data);
		if (format[i] == 'l')
			data->l_count++;
		if (format[i] == 'L')
			data->count_l++;
		if (format[i] == 'h')
			data->h_count++;
	}
	ft_check_size(data);
	data->type = format[index];
	return (index);
}
