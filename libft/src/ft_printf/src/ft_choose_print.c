/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 14:00:29 by ramory-l          #+#    #+#             */
/*   Updated: 2019/09/16 15:53:20 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_choose_print(va_list ap, t_printf *data, t_buffer *bf)
{
	if (data->type == 'd' || data->type == 'i' ||
		data->type == 'o' || data->type == 'u' ||
		data->type == 'x' || data->type == 'X')
		ft_dioux_x(ap, data, bf);
	if (data->type == 'c')
		ft_print_char(ap, data, bf);
	if (data->type == 's')
		ft_print_string(ap, data, bf);
	if (data->type == 'p')
		ft_print_ptr(ap, data, bf);
	if (data->type == '%')
		ft_print_percent(data, bf);
	if (data->type == 'f')
		ft_longdouble(ap, data, bf);
}
