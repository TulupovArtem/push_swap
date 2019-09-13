/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramory-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 14:02:27 by ramory-l          #+#    #+#             */
/*   Updated: 2019/06/15 14:02:28 by ramory-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_width(t_printf *data, t_buffer *bf)
{
	if (data->width > data->len && !(data->flags & FLAG_MINUS))
		ft_fill_spaces_oux(data, bf);
	else if (data->width > data->len && data->flags & FLAG_MINUS)
	{
		ft_fill_bf(data, bf);
		ft_fill_spaces_oux(data, bf);
		return (1);
	}
	return (0);
}

void		ft_print_percent(t_printf *data, t_buffer *bf)
{
	bf->temp[0] = '%';
	data->len = 1;
	if (ft_width(data, bf))
		return ;
	ft_fill_bf(data, bf);
}
