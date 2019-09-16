/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 14:00:20 by ramory-l          #+#    #+#             */
/*   Updated: 2019/09/16 15:54:02 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_manage_flags(t_printf *data)
{
	if (data->flags & FLAG_MINUS && data->flags & FLAG_ZERO)
		data->flags &= ~FLAG_ZERO;
	if (data->flags & FLAG_PLUS && data->flags & FLAG_SPACE)
		data->flags &= ~FLAG_SPACE;
	if (data->flags & FLAG_ZERO && data->accuracy > 0)
		data->flags &= ~FLAG_ZERO;
}

t_cc			*ft_check_ptc(va_list ap,
t_cc *format, t_printf *data, t_buffer *bf)
{
	int type_index;

	type_index = ft_specifier_format(format, data);
	if (type_index == 0)
		return ("");
	ft_manage_flags(data);
	ft_choose_print(ap, data, bf);
	return (format + type_index + 1);
}
