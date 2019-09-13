/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramory-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 14:02:34 by ramory-l          #+#    #+#             */
/*   Updated: 2019/06/15 14:02:35 by ramory-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_str_tobuff(char *str, t_printf *data, t_buffer *bf)
{
	int i;

	i = 0;
	while (i < data->len)
	{
		bf->buffer[bf->s] = str[i];
		bf->s++;
		i++;
		ft_check_buffer(data, bf);
	}
}

static int	ft_width_accuracy(char *str, t_printf *data, t_buffer *bf)
{
	if (data->acc && data->len > data->accuracy)
		data->len = data->accuracy;
	if (data->width > data->len && data->flags & FLAG_MINUS)
	{
		ft_str_tobuff(str, data, bf);
		ft_fill_spaces_oux(data, bf);
		return (1);
	}
	if (data->width > data->len && !(data->flags & FLAG_MINUS))
	{
		ft_fill_spaces_oux(data, bf);
		ft_str_tobuff(str, data, bf);
		return (1);
	}
	return (0);
}

void		ft_print_string(va_list ap, t_printf *data, t_buffer *bf)
{
	char *str;

	str = va_arg(ap, char *);
	if (!str)
	{
		str = "(null)";
		data->len = 6;
		ft_str_tobuff(str, data, bf);
		return ;
	}
	data->len = ft_strlen(str);
	if (ft_width_accuracy(str, data, bf))
		return ;
	ft_str_tobuff(str, data, bf);
}
