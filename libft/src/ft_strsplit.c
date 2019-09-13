/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:31:22 by idunaver          #+#    #+#             */
/*   Updated: 2018/12/20 16:57:12 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	**ft_free(size_t j, size_t i, char **split)
{
	while (j != i)
	{
		ft_memdel((void**)split[j]);
		j++;
	}
	free(split);
	split = NULL;
	return (split);
}

static	size_t	ft_letters(char *s, char c)
{
	size_t	l;

	l = 0;
	while (*s != c && *s != '\0')
	{
		l++;
		s++;
	}
	return (l);
}

static	size_t	ft_words(char *h, char c)
{
	size_t	i;

	i = 1;
	while (*h == c)
		h++;
	while (*h != c && *h != '\0')
	{
		while (*h != c && *h != '\0')
			h++;
		i++;
		while (*h == c && *h != '\0')
			h++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	j;

	j = 0;
	if (!s)
		return (NULL);
	i = ft_words((char*)s, c);
	if (!(split = (char **)malloc((i + 1) * sizeof(char *))))
		return (NULL);
	while (j != i - 1)
	{
		while (*s == c)
			s++;
		if ((split[j] = ft_strsub(s, 0, ft_letters((char *)s, c))) == NULL)
			return (ft_free(j, i, split));
		j++;
		while (*s != c && *s != '\0')
			s++;
	}
	split[j] = NULL;
	return (split);
}
