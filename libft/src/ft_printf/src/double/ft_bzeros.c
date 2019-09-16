/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzeros.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 20:11:00 by idunaver          #+#    #+#             */
/*   Updated: 2019/09/16 16:33:21 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_strdupandfree(t_workwithmantis wwm, char *result)
{
	free(result);
	result = ft_strdup(wwm.result_tmp);
	free(wwm.result_tmp);
	return (result);
}

void			ft_freedoubletochar(t_doubletochar doublechar)
{
	free(doublechar.inttochar);
	free(doublechar.nulls);
	free(doublechar.fractiontochar);
}

void			ft_nulldoubletochar(t_doubletochar *doublechar)
{
	doublechar->inttochar = NULL;
	doublechar->fractiontochar = NULL;
	doublechar->nulls = NULL;
}

t_arrayint		ft_bzeroarrs(void)
{
	t_arrayint	arrayint;
	int			lenarr;
	int			iarr;

	iarr = 0;
	lenarr = LEN_ARR;
	arrayint.lenarr = LEN_ARR;
	while (lenarr--)
	{
		arrayint.intresult[iarr] = 0;
		arrayint.inttmp[iarr] = 0;
		iarr++;
	}
	arrayint.iarr = 0;
	arrayint.jarr = 0;
	return (arrayint);
}

t_arrayint		ft_bzerotmparr(t_arrayint arrayint)
{
	int iarr;
	int lenarr;

	lenarr = arrayint.jarr;
	iarr = 0;
	while (lenarr--)
	{
		arrayint.inttmp[iarr] = 0;
		iarr++;
	}
	arrayint.jarr = 0;
	return (arrayint);
}
