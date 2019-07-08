/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:34:37 by idunaver          #+#    #+#             */
/*   Updated: 2018/12/18 19:04:51 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_helper(char *nh, char *nn, size_t len)
{
	size_t	i;

	i = 0;
	while (len != 0)
	{
		if (*nn == *nh)
		{
			nh++;
			nn++;
			i++;
			if (*nh != *nn && *nn != '\0')
			{
				nh = nh - i + 1;
				nn = nn - i;
				len = (i - 1) + len;
				i = 0;
			}
			else if (*nn == '\0')
				return (nh - i);
		}
		else
			nh++;
		len--;
	}
	return (NULL);
}

char			*ft_strnstr(const char *haystack, const char *needle
, size_t len)
{
	char	*nh;
	char	*nn;
	size_t	i;
	size_t	j;

	nh = (char *)haystack;
	nn = (char *)needle;
	i = ft_strlen(needle);
	j = ft_strlen(haystack);
	if (i > j)
		return (NULL);
	if (*nh == '\0' && *nn != '\0')
		return (NULL);
	else if (*nh != '\0' && *nn == '\0')
		return (nh);
	else if (*nh == '\0' && *nn == '\0')
		return (nn);
	return (ft_helper(nh, nn, len));
}
