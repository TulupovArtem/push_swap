/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 18:42:22 by idunaver          #+#    #+#             */
/*   Updated: 2019/08/27 18:43:58 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long		ft_atoll(const char *str)
{
	long long	r;
	long long	sign;

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
	return (sign * r);
}
