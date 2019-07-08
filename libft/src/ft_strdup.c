/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 13:36:15 by idunaver          #+#    #+#             */
/*   Updated: 2018/12/20 16:56:41 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dsrc;

	i = 0;
	while (s1[i] != '\0')
		i++;
	dsrc = (char *)malloc((i + 1) * sizeof(char));
	if (!dsrc)
	{
		errno = ENOMEM;
		return (NULL);
	}
	i = 0;
	while (s1[i] != '\0')
	{
		dsrc[i] = s1[i];
		i++;
	}
	dsrc[i] = '\0';
	return (dsrc);
}
