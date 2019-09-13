/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_arithmetic.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 19:47:45 by idunaver          #+#    #+#             */
/*   Updated: 2019/06/15 16:45:51 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_maxindex(t_arrayint arrayint)
{
	return (arrayint.iarr > arrayint.jarr ? arrayint.iarr : arrayint.jarr);
}

int			ft_exponentiation(int power, int number)
{
	int result;

	result = number;
	if (power == 0)
		result = 1;
	else
		while (power-- != 1)
			result *= number;
	return (result);
}

t_arrayint	ft_multlongnumbyaten(t_arrayint arrayint)
{
	unsigned long long int	current;
	unsigned long long int	remainder;
	int						iarr;

	iarr = 0;
	remainder = 0;
	current = 0;
	while (iarr < arrayint.iarr || remainder)
	{
		if (iarr == arrayint.lenarr)
			return (arrayint);
		if (arrayint.intresult[iarr] != 0)
			current = remainder + arrayint.intresult[iarr] * 10;
		else
			current = remainder;
		arrayint.intresult[iarr] = current % MAX_CELL;
		remainder = current / MAX_CELL;
		iarr++;
	}
	arrayint.iarr = iarr;
	return (arrayint);
}

t_arrayint	ft_multlongnumbyashort(t_arrayint arrayint,
int power, int base)
{
	unsigned long long int	current;
	unsigned long long int	remainder;
	int						jarr;

	jarr = 0;
	remainder = 0;
	current = 0;
	if (arrayint.inttmp[jarr] == 0)
	{
		arrayint.inttmp[jarr] = ft_exponentiation(power, base);
		jarr++;
	}
	while (jarr < arrayint.jarr || remainder)
	{
		if (jarr == arrayint.lenarr)
			return (arrayint);
		current = remainder + arrayint.inttmp[jarr] *
		ft_exponentiation(power, base);
		arrayint.inttmp[jarr] = current % MAX_CELL;
		remainder = current / MAX_CELL;
		jarr++;
	}
	arrayint.jarr = jarr;
	return (arrayint);
}

t_arrayint	ft_summpower(t_arrayint arrayint)
{
	unsigned long long int	remminder;
	unsigned long long int	current;
	int						iarr;

	remminder = 0;
	iarr = 0;
	current = 0;
	while (iarr < ft_maxindex(arrayint) || remminder)
	{
		if (iarr == arrayint.lenarr)
			return (arrayint);
		current = arrayint.intresult[iarr] + arrayint.inttmp[iarr] + remminder;
		remminder = current / MAX_CELL;
		if (current)
			arrayint.intresult[iarr] = current % MAX_CELL;
		iarr++;
	}
	arrayint.iarr = iarr;
	return (arrayint);
}
