/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 13:59:43 by ramory-l          #+#    #+#             */
/*   Updated: 2019/06/15 17:03:18 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_find_length(t_ulli value, int base)
{
	int len;

	len = 0;
	while (value)
	{
		value /= base;
		len++;
	}
	return (len);
}

void		ft_itoa_base(t_ulli value, int base, t_printf *data, t_buffer *bf)
{
	int		len;
	char	*radix;

	if (base == 17)
	{
		radix = "0123456789ABCDEF";
		base--;
	}
	else
		radix = "0123456789abcdef";
	if (value == 0)
	{
		bf->temp[0] = '0';
		data->len = 1;
		return ;
	}
	len = ft_find_length(value, base);
	data->len = len;
	while (len--)
	{
		bf->temp[len] = radix[value % base];
		value /= base;
	}
}
