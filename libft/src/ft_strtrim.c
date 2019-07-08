/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 14:10:35 by idunaver          #+#    #+#             */
/*   Updated: 2018/12/18 19:28:20 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_help(char *h, size_t j)
{
	while (*h != '\0')
		h++;
	h--;
	while (*h == ' ' || *h == '\n' || *h == '\t')
	{
		h--;
		j--;
	}
	return (j);
}

char			*ft_strtrim(char const *s)
{
	char	*h;
	char	*s3;
	size_t	j;

	if (s == NULL)
		return (NULL);
	j = ft_strlen(s);
	h = (char*)s;
	while (*h == ' ' || *h == '\n' || *h == '\t')
	{
		h++;
		j--;
	}
	if (*h == '\0')
		return (ft_strnew(0));
	j = ft_help(h, j);
	if ((s3 = ft_strnew(j)) == NULL)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	ft_strncpy(s3, s, j);
	s3[j] = '\0';
	return (s3);
}
