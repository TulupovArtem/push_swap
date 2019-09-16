/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_workwithmantis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 19:42:14 by idunaver          #+#    #+#             */
/*   Updated: 2019/09/16 16:33:29 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_fillnulls(int exp, char *fraction, unsigned long mantis)
{
	int		power;
	int		countnull;
	int		lenfractional;
	char	*result;

	lenfractional = 0;
	power = 0;
	countnull = 0;
	lenfractional = ft_strlen(fraction);
	lenfractional--;
	power = ft_minpowerfractional(mantis);
	countnull = 64 - power - exp - lenfractional;
	if (countnull <= 0)
		return (NULL);
	result = (char*)malloc((countnull + 1) * sizeof(char));
	result[countnull] = '\0';
	result = ft_memset(result, '0', countnull);
	return (result);
}

t_arrayint	ft_findingfractionpower(t_longdouble longdouble,
int numofintbits, t_powerbits bitspower)
{
	int			bit;
	t_arrayint	arrayint;

	bitspower = ft_bitspowercontructor(bitspower);
	arrayint = ft_bzeroarrs();
	while (bitspower.numofbits >= 0)
	{
		bit = ((longdouble.mantis & (1UL << bitspower.numofbits)) != 0) ? 1 : 0;
		numofintbits--;
		bitspower.numofbits--;
		if (numofintbits < 0)
		{
			bitspower.power++;
			if (bit == 1)
			{
				bitspower.flag = 1;
				arrayint = ft_bitsandpower(arrayint, bitspower);
			}
			if (bitspower.flag == 1 && (longdouble.mantis << (63 -
			bitspower.numofbits)) != 0)
				arrayint = ft_multlongnumbyaten(arrayint);
		}
	}
	return (arrayint);
}

t_arrayint	ft_findingintpower(t_longdouble longdouble,
int numofintbits, t_powerbits bitspower)
{
	int			numofbits;
	int			bit;
	t_arrayint	arrayint;

	bit = 0;
	numofbits = 63;
	bitspower.base = 2;
	arrayint = ft_bzeroarrs();
	while (numofbits >= 0)
	{
		bit = ((longdouble.mantis & (1UL << numofbits)) != 0) ? 1 : 0;
		numofbits--;
		bitspower.power--;
		if (bitspower.power < 0)
			return (arrayint);
		if (bit == 1)
		{
			arrayint = ft_separationpower(bitspower, arrayint);
			arrayint = ft_summpower(arrayint);
			arrayint = ft_bzerotmparr(arrayint);
		}
		numofintbits--;
	}
	return (arrayint);
}

char		*ft_workwithmantis(t_longdouble longdouble)
{
	t_powerbits			bitspower;
	t_arrayint			arrayint;
	t_doubletochar		doublechar;
	char				*result;
	t_workwithmantis	wwm;

	result = NULL;
	wwm.numofintbits = longdouble.exp - LDBL_MAX_EXP + 2;
	bitspower.power = wwm.numofintbits;
	ft_nulldoubletochar(&doublechar);
	arrayint = ft_findingintpower(longdouble, wwm.numofintbits, bitspower);
	doublechar.inttochar = ft_numtochar(arrayint);
	arrayint = ft_findingfractionpower(longdouble, wwm.numofintbits, bitspower);
	doublechar.fractiontochar = ft_numtochar(arrayint);
	doublechar.nulls = ft_fillnulls(wwm.numofintbits,
	doublechar.fractiontochar, longdouble.mantis);
	result = ft_doublecat(result, doublechar, wwm);
	ft_freedoubletochar(doublechar);
	return (result);
}
