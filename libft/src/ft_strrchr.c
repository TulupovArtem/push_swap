/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:17:14 by idunaver          #+#    #+#             */
/*   Updated: 2018/12/06 18:40:26 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*n;

	i = ft_strlen(s);
	n = (char *)s;
	i++;
	while (*n != '\0')
		n++;
	while (i > 0)
	{
		if ((char)c == *n)
			return (n);
		n--;
		i--;
	}
	if (c == '\0')
		return (n);
	return (NULL);
}
