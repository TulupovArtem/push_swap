/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_sign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramory-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 17:12:32 by ramory-l          #+#    #+#             */
/*   Updated: 2019/06/15 13:59:17 by ramory-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_add_sign(t_printf *data, t_buffer *bf)
{
	if (data->sign)
	{
		bf->buffer[bf->s] = '-';
		bf->s++;
		ft_check_buffer(data, bf);
	}
	if (!data->sign && data->flags & FLAG_PLUS)
	{
		bf->buffer[bf->s] = '+';
		bf->s++;
		ft_check_buffer(data, bf);
	}
}
