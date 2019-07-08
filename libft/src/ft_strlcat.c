/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 14:01:56 by idunaver          #+#    #+#             */
/*   Updated: 2018/12/06 18:04:44 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*s;
	char	*d;
	size_t	i;
	size_t	j;

	s = (char*)src;
	d = dst;
	i = ft_strlen(s);
	j = ft_strlen(dst);
	if (size < j + 1)
		return (i + size);
	else
		ft_strncat(d, s, (size - j - 1));
	return (i + j);
}
