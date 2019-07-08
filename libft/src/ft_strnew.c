/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:29:55 by idunaver          #+#    #+#             */
/*   Updated: 2018/12/18 20:08:44 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*m;

	if (size + 1 == 0)
		return (NULL);
	m = ft_memalloc(size + 1);
	m == NULL ? NULL : ft_memset(m, '\0', size);
	return (m);
}
