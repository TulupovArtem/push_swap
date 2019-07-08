/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:25:48 by idunaver          #+#    #+#             */
/*   Updated: 2018/12/20 16:56:54 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	size_t	ii;
	char	*n;

	if (!s || !f)
		return (NULL);
	i = ft_strlen(s);
	ii = i;
	n = (char *)malloc((i + 1) * sizeof(char));
	if (!n)
		return (NULL);
	while (i--)
		*n++ = f(*s++);
	*n = '\0';
	while (ii--)
		n--;
	return (n);
}
