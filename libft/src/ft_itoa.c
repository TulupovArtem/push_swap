/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:26:35 by ramory-l          #+#    #+#             */
/*   Updated: 2019/06/15 17:10:45 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int			ft_intleng(unsigned long long int n)
{
	int		i;

	i = 0;
	while (n /= 10)
		i++;
	return (i + 1);
}

char				*ft_itoa(unsigned long long int n)
{
	int						i;
	int						leng;
	char					*str;
	unsigned long long int	b;

	b = n;
	i = 0;
	leng = ft_intleng(b);
	str = ft_memalloc(leng + 1);
	while (leng-- && str[leng] != '-')
	{
		str[leng] = '0' + (b % 10);
		b /= 10;
	}
	return (str);
}
