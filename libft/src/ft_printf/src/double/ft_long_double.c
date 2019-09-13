/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 18:37:02 by idunaver          #+#    #+#             */
/*   Updated: 2019/06/20 21:15:44 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arrayint	ft_fillarray(t_powerbits bitspower, t_arrayint arrayint)
{
	if (bitspower.countpower)
	{
		while (bitspower.countpower--)
			arrayint = ft_multlongnumbyashort(arrayint,
			MAX_POWER, bitspower.base);
	}
	if (bitspower.remainpower || (!bitspower.remainpower
	&& !bitspower.countpower))
		arrayint = ft_multlongnumbyashort(arrayint,
		bitspower.remainpower, bitspower.base);
	return (arrayint);
}

t_powerbits	ft_bitspowercontructor(t_powerbits bitspower)
{
	bitspower.flag = 0;
	bitspower.numofbits = 63;
	bitspower.base = 5;
	bitspower.power = (bitspower.power < 0) ? bitspower.power * -1 : 0;
	return (bitspower);
}

char		*ft_numtochar(t_arrayint arrayint)
{
	char	*result;
	int		i;
	int		lenarr;
	t_temp	temp;

	i = --arrayint.iarr;
	result = ft_strnew(0);
	while (i >= 0)
	{
		temp.tmp = ft_itoa(arrayint.intresult[i]);
		lenarr = ft_strlen(temp.tmp);
		if (lenarr != 8 && *result)
			temp = ft_fornulls(lenarr, temp);
		temp.result_temp = ft_strjoin(result, temp.tmp);
		ft_strdel(&result);
		result = ft_strdup(temp.result_temp);
		ft_strdel(&temp.result_temp);
		ft_strdel(&temp.tmp);
		i--;
	}
	return (result);
}

int			ft_minpowerfractional(unsigned long mantis)
{
	int	bitindex;
	int	power;
	int	bit;

	bit = 0;
	power = 0;
	bitindex = 0;
	while (bitindex < 64)
	{
		bit = (mantis & (1UL << bitindex)) != 0 ? 1 : 0;
		if (bit == 1)
		{
			power = bitindex;
			break ;
		}
		bitindex++;
	}
	return (power);
}

void		ft_longdouble(va_list ap, t_printf *data, t_buffer *bf)
{
	t_longdoubletounsignedlong	bits;
	t_longdouble				longdouble;
	char						*result;

	if (!data->acc)
		data->accuracy = 6;
	if (data->size & SIZE_LLL)
		bits.longdouble = va_arg(ap, long double);
	else
		bits.longdouble = va_arg(ap, double);
	longdouble.sign = (*(&bits.unsignedlong + 1)) & (1 << 15) ? 1 : 0;
	longdouble.exp = (int)(*(&bits.unsignedlong + 1) & 0x7fffL);
	longdouble.mantis = bits.unsignedlong;
	result = ft_workwithmantis(longdouble);
	ft_printlongdouble(result, data, longdouble.sign, bf);
	free(result);
}
