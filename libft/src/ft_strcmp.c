/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 16:48:52 by idunaver          #+#    #+#             */
/*   Updated: 2018/12/17 19:17:11 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *ns1;
	unsigned char *ns2;

	ns1 = (unsigned char *)s1;
	ns2 = (unsigned char *)s2;
	if (*ns1 == '\0' || *ns2 == '\0')
		return (*ns1 - *ns2);
	else
	{
		while (*ns1 != '\0')
		{
			if (*ns1 != *ns2)
				return (*ns1 - *ns2);
			ns1++;
			ns2++;
		}
		if (*ns1 == '\0')
			return (*ns1 - *ns2);
	}
	return (0);
}
