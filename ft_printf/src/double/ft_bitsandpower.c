/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitsandpower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 20:15:20 by idunaver          #+#    #+#             */
/*   Updated: 2019/06/20 21:19:48 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_temp		ft_fornulls(int lenarr, t_temp temp)
{
	char	*nulls;

	nulls = (char*)malloc((8 - lenarr + 1) * sizeof(char));
	nulls[8 - lenarr] = '\0';
	nulls = ft_memset(nulls, '0', 8 - lenarr);
	temp.temp = ft_strjoin(nulls, temp.tmp);
	ft_strdel(&temp.tmp);
	temp.tmp = ft_strdup(temp.temp);
	ft_strdel(&temp.temp);
	ft_strdel(&nulls);
	return (temp);
}

char		*ft_doublecat(char *result, t_doubletochar doublechar,
t_workwithmantis wwm)
{
	result = ft_strjoin(*doublechar.inttochar ?
	doublechar.inttochar : "0", ".");
	if (doublechar.nulls)
	{
		wwm.result_tmp = ft_strjoin(result, doublechar.nulls);
		result = ft_strdupandfree(wwm, result);
	}
	wwm.result_tmp = ft_strjoin(result, *doublechar.fractiontochar ?
	doublechar.fractiontochar : "0");
	result = ft_strdupandfree(wwm, result);
	return (result);
}

t_arrayint	ft_separationpower(t_powerbits bitspower,
t_arrayint arrayint)
{
	bitspower.countpower = 0;
	bitspower.remainpower = 0;
	if (bitspower.power >= MAX_POWER)
		bitspower.countpower = bitspower.power / MAX_POWER;
	bitspower.remainpower = bitspower.power % MAX_POWER;
	return (ft_fillarray(bitspower, arrayint));
}

t_arrayint	ft_bitsandpower(t_arrayint arrayint, t_powerbits bitspower)
{
	arrayint = ft_separationpower(bitspower, arrayint);
	arrayint = ft_summpower(arrayint);
	arrayint = ft_bzerotmparr(arrayint);
	return (arrayint);
}
