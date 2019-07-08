/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 18:54:53 by idunaver          #+#    #+#             */
/*   Updated: 2018/12/06 14:53:42 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*d;
	char	*s;

	d = dst;
	s = (char*)src;
	while (len > 0)
	{
		if (*s != '\0')
		{
			*d = *s;
			s++;
		}
		else
			*d = '\0';
		d++;
		len--;
	}
	return (dst);
}
