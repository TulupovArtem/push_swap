/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramory-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 14:00:51 by ramory-l          #+#    #+#             */
/*   Updated: 2019/06/15 14:00:52 by ramory-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(va_list ap, t_printf *data, t_buffer *bf)
{
	data->len = 1;
	if (data->width > data->len && !(data->flags & FLAG_MINUS) &&
		!(data->flags & FLAG_ZERO))
		ft_fill_spaces_oux(data, bf);
	bf->buffer[bf->s] = va_arg(ap, int);
	bf->s++;
	if (data->width > data->len && data->flags & FLAG_MINUS)
		ft_fill_spaces_oux(data, bf);
	if (data->width > data->len && data->flags & FLAG_ZERO)
		ft_fill_zeroes_oux(data, bf);
}
