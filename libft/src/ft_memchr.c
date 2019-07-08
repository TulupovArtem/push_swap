/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:21:36 by idunaver          #+#    #+#             */
/*   Updated: 2018/12/06 13:38:08 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *new;

	new = (unsigned char*)s;
	while (n != 0)
	{
		if (*new == (unsigned char)c)
			return (new);
		new++;
		n--;
	}
	return (NULL);
}
