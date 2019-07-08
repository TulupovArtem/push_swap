/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:39:30 by idunaver          #+#    #+#             */
/*   Updated: 2018/12/18 16:26:08 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_helpstrcmp(const char *s1, const char *s2)
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
	}
	return (0);
}

char		*ft_strstr(const char *haystack, const char *needle)
{
	unsigned char *nh;
	unsigned char *nn;

	nh = (unsigned char *)haystack;
	nn = (unsigned char *)needle;
	if (*nh == '\0' && *nn != '\0')
		return (NULL);
	else if (*nh != '\0' && *nn == '\0')
		return ((char*)nh);
	else if (*nh == '\0' && *nn == '\0')
		return ((char*)nn);
	while (*nh != '\0')
	{
		if (*nn == *nh)
		{
			if (ft_helpstrcmp((char *)nn, (char *)nh) == 0)
				return ((char*)nh);
		}
		nh++;
	}
	return (NULL);
}
