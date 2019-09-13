/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramory-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:30:43 by ramory-l          #+#    #+#             */
/*   Updated: 2018/11/27 18:58:23 by ramory-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_issym(char c, char sym)
{
	return (c == sym);
}

static	int		ft_countwords(const char *str, char c)
{
	int	word;
	int	counter;

	word = 0;
	counter = 0;
	while (*str)
	{
		if (!ft_issym(*str, c))
		{
			if (word == 0)
			{
				word = 1;
				counter++;
			}
		}
		else
			word = 0;
		str++;
	}
	return (counter);
}

char			**ft_strsplit(char const *s, char c)
{
	int		arr[3];
	char	**str;

	ft_memset(arr, 0, sizeof(arr));
	if (!s ||
		!(str = (char **)malloc(sizeof(char *) * (ft_countwords(s, c) + 1))))
		return (NULL);
	while (s[arr[0]])
	{
		while (!ft_issym(s[arr[0] + arr[1]], c) && s[arr[0] + arr[1]])
			arr[1]++;
		if (arr[0] < arr[0] + arr[1])
		{
			str[arr[2]] = ft_strsub(s, arr[0], arr[1]);
			if (str[arr[2]] == NULL)
				return (NULL);
			arr[2]++;
			arr[0] = arr[0] + arr[1];
			arr[1] = 0;
		}
		arr[0]++;
	}
	str[ft_countwords(s, c)] = NULL;
	return (str);
}
