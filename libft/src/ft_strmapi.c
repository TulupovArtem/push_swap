/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 18:07:17 by idunaver          #+#    #+#             */
/*   Updated: 2018/12/20 16:57:00 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	ii;
	size_t	iii;
	char	*n;

	iii = 0;
	if (!s || !f)
		return (NULL);
	i = ft_strlen(s);
	ii = i;
	n = (char *)malloc((i + 1) * sizeof(char));
	if (!n)
		return (NULL);
	while (i--)
		*n++ = f(iii++, *s++);
	*n = '\0';
	while (ii--)
		n--;
	return (n);
}
