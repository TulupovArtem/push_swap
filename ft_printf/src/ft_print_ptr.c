/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramory-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 16:34:12 by ramory-l          #+#    #+#             */
/*   Updated: 2019/06/22 16:49:51 by ramory-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_oct(t_printf *data, t_buffer *bf)
{
	bf->buffer[bf->s] = '0';
	bf->s++;
	ft_check_buffer(data, bf);
	bf->buffer[bf->s] = 'x';
	bf->s++;
	ft_check_buffer(data, bf);
}

void		ft_print_ptr(va_list ap, t_printf *data, t_buffer *bf)
{
	ft_itoa_base((t_ulli)va_arg(ap, void *), 16, data, bf);
	if (data->len < data->width - 2 && !(data->flags & FLAG_MINUS) &&
		!(data->flags & FLAG_ZERO))
	{
		data->width -= 2;
		ft_fill_spaces_oux(data, bf);
	}
	ft_oct(data, bf);
	if (data->width > data->len && data->flags & FLAG_ZERO)
	{
		data->width -= 2;
		ft_fill_zeroes_oux(data, bf);
	}
	if (bf->temp[0] == '0' && data->acc && !data->accuracy)
		return ;
	if (data->accuracy > data->len)
		ft_fill_zeroes_di(data, bf);
	ft_fill_bf(data, bf);
	if (data->len < data->width - 2 && data->flags & FLAG_MINUS)
	{
		data->width -= 2;
		ft_fill_spaces_oux(data, bf);
	}
}
