/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:47:41 by idunaver          #+#    #+#             */
/*   Updated: 2018/12/06 13:23:12 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *a;
	unsigned char *b;

	a = (unsigned char*)src;
	b = (unsigned char*)dst;
	if (b <= a)
	{
		ft_memcpy(b, a, len);
	}
	else
	{
		a = a + len - 1;
		b = b + len - 1;
		while (len != 0)
		{
			*b = *a;
			a--;
			b--;
			len--;
		}
	}
	return (dst);
}
