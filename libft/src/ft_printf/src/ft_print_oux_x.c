/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_oux_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 14:02:19 by ramory-l          #+#    #+#             */
/*   Updated: 2019/06/20 20:49:16 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_oct(t_printf *data, t_buffer *bf)
{
	char *temp;

	if (data->flags & FLAG_OCT && bf->temp[0])
	{
		if (data->type == 'x' || data->type == 'X')
		{
			if (data->type == 'x')
				temp = "0x";
			if (data->type == 'X')
				temp = "0X";
			bf->buffer[bf->s] = temp[0];
			bf->buffer[bf->s + 1] = temp[1];
			bf->s += 2;
			if (!(data->flags & FLAG_ZERO))
				data->width -= 2;
		}
		else if (data->type == 'o')
		{
			temp = "0";
			bf->buffer[bf->s] = temp[0];
			bf->s++;
			if (!(data->flags & FLAG_ZERO))
				data->width -= 1;
		}
	}
}

static void	ft_accuracy(t_printf *data, t_buffer *bf)
{
	if (data->accuracy > data->len && data->accuracy > data->width &&
		data->width > 0)
		ft_fill_zeroes_di(data, bf);
	if (data->accuracy > data->len && !data->width && !(data->flags & FLAG_OCT))
		ft_fill_zeroes_di(data, bf);
	if (data->accuracy > data->len && !data->width && data->flags & FLAG_OCT)
	{
		ft_oct(data, bf);
		if (data->flags & FLAG_OCT && data->type == 'o')
			data->accuracy--;
		ft_fill_zeroes_di(data, bf);
	}
}

static void	ft_accuracy_width(t_printf *data, t_buffer *bf)
{
	if (data->accuracy > data->len && data->accuracy < data->width)
		ft_fill_zeroes_di(data, bf);
}

static int	ft_width(t_printf *data, t_buffer *bf)
{
	ft_accuracy(data, bf);
	if (data->width > data->len && !(data->flags & FLAG_ZERO) &&
		!(data->flags & FLAG_MINUS))
	{
		ft_fill_spaces_oux(data, bf);
		ft_accuracy_width(data, bf);
		ft_oct(data, bf);
	}
	if (data->width > data->len && data->flags & FLAG_ZERO)
	{
		ft_oct(data, bf);
		ft_fill_zeroes_oux(data, bf);
	}
	if (data->width > data->len && data->flags & FLAG_MINUS)
	{
		ft_oct(data, bf);
		ft_accuracy_width(data, bf);
		ft_fill_bf(data, bf);
		ft_fill_spaces_oux(data, bf);
		return (1);
	}
	if (!data->width)
		ft_oct(data, bf);
	return (0);
}

void		ft_print_oux_x(t_printf *data, t_buffer *bf)
{
	if (bf->temp[0] == '0')
	{
		if (data->acc && data->type == 'o' && data->flags & FLAG_OCT)
		{
			ft_fill_bf(data, bf);
			return ;
		}
		if (!data->acc)
		{
			ft_fill_bf(data, bf);
			return ;
		}
		else
		{
			bf->temp[0] = '\0';
			data->len = 0;
		}
	}
	if (ft_width(data, bf))
		return ;
	ft_fill_bf(data, bf);
}
