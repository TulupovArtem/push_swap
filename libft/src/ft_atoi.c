/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 17:36:00 by idunaver          #+#    #+#             */
/*   Updated: 2018/12/18 18:26:44 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long long	r;
	int			sign;

	sign = 1;
	r = 0;
	while (((*str >= 9 && *str <= 13) || *str == ' ') && *str != '\0')
		str++;
	if (*str == 43)
		str++;
	else if (*str == 45)
	{
		sign = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		if (r * 10 / 10 != r)
			return (sign == 1 ? -1 : 0);
		r = r * 10;
		if (r + *str - '0' < 0)
			return (sign == 1 ? -1 : 0);
		r = r + *str++ - '0';
	}
	return (sign * (int)r);
}
