/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_buffer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramory-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 15:26:05 by ramory-l          #+#    #+#             */
/*   Updated: 2019/06/15 14:30:41 by ramory-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_buffer(t_printf *data, t_buffer *bf)
{
	if (bf->s == 511)
	{
		write(1, bf->buffer, bf->s);
		data->printed += bf->s;
		bf->s = 0;
	}
}
