/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:17:36 by idunaver          #+#    #+#             */
/*   Updated: 2018/12/20 16:08:28 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_counter(int c, size_t i)
{
	if (c == 0)
		i++;
	while (c != 0)
	{
		c = c / 10;
		i++;
	}
	return (i);
}

static	char	*ft_help(char *s, size_t i, unsigned int n, size_t f)
{
	while (i > 0)
	{
		s[i - 1] = (n % 10) + '0';
		i--;
		n = n / 10;
		if (i == 0 && f == 1)
			s[i] = 45;
	}
	return (s);
}

char			*ft_itoa(int n)
{
	size_t			i;
	char			*s;
	unsigned int	c;
	size_t			f;

	i = 0;
	c = n;
	f = 0;
	i = ft_counter(c, i);
	if (n < 0)
	{
		i++;
		n = n * (-1);
		f++;
	}
	s = ft_strnew(i);
	if (!s)
		return (NULL);
	return (ft_help(s, i, n, f));
}
