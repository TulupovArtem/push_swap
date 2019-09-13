/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_bf_zeroes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramory-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 15:15:29 by ramory-l          #+#    #+#             */
/*   Updated: 2019/06/15 13:59:32 by ramory-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fill_zeroes_di(t_printf *data, t_buffer *bf)
{
	int i;

	i = data->len;
	while (i < data->accuracy)
	{
		bf->buffer[bf->s] = '0';
		bf->s++;
		i++;
		ft_check_buffer(data, bf);
	}
}

void	ft_fill_zeroes_oux(t_printf *data, t_buffer *bf)
{
	int zeroes;

	zeroes = data->width - data->len + bf->s;
	if (data->flags & FLAG_OCT)
	{
		if (data->type == 'x' || data->type == 'X')
			zeroes -= 2;
		if (data->type == 'o')
			zeroes--;
	}
	while (bf->s < zeroes)
	{
		bf->buffer[bf->s] = '0';
		bf->s++;
		ft_check_buffer(data, bf);
	}
}
