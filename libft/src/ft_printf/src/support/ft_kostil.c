/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kostil.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramory-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 16:50:54 by ramory-l          #+#    #+#             */
/*   Updated: 2019/06/22 16:51:09 by ramory-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_width(t_printf *data, t_buffer *bf)
{
	if (data->flags & FLAG_PLUS || data->sign)
		data->width--;
	if (data->flags & FLAG_MINUS)
	{
		ft_add_sign(data, bf);
		ft_fill_bf(data, bf);
		ft_fill_spaces_di(data, bf);
	}
	else
	{
		if (data->flags & FLAG_ZERO)
		{
			ft_add_sign(data, bf);
			ft_fill_spaces_di(data, bf);
			ft_fill_bf(data, bf);
		}
		else
		{
			ft_fill_spaces_di(data, bf);
			ft_add_sign(data, bf);
			ft_fill_bf(data, bf);
		}
	}
}

static void	ft_check(t_printf *data, t_buffer *bf)
{
	if (data->flags & FLAG_ZERO)
	{
		if (data->flags & FLAG_SPACE)
		{
			bf->buffer[bf->s] = ' ';
			bf->s++;
			ft_check_buffer(data, bf);
			data->width--;
		}
		ft_add_sign(data, bf);
		ft_fill_spaces_di(data, bf);
		ft_fill_bf(data, bf);
	}
}

int			ft_kostil(t_printf *data, t_buffer *bf)
{
	if (bf->temp[0] == '0' && data->acc && !data->accuracy)
	{
		bf->temp[0] = ' ';
		if (data->width > data->len)
			ft_width(data, bf);
		return (1);
	}
	if (data->flags & FLAG_PLUS || data->sign)
		data->width--;
	if (data->flags & FLAG_MINUS)
	{
		ft_add_sign(data, bf);
		ft_fill_bf(data, bf);
		ft_fill_spaces_di(data, bf);
	}
	ft_check(data, bf);
	return (1);
}
