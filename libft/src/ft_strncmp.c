/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 17:01:53 by idunaver          #+#    #+#             */
/*   Updated: 2018/12/17 19:28:57 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *ns1;
	unsigned char *ns2;

	ns1 = (unsigned char *)s1;
	ns2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	if (*s1 == '\0')
		return (*ns1 - *ns2);
	while (*ns1 != '\0' && n != 1)
	{
		if (*ns2 == '\0' || *ns1 == '\0')
			return (*ns1 - *ns2);
		if (*ns1 != *ns2)
			return (*ns1 - *ns2);
		ns1++;
		ns2++;
		n--;
	}
	return (*ns1 - *ns2);
}
