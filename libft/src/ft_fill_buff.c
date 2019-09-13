/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_buff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 13:52:58 by ramory-l          #+#    #+#             */
/*   Updated: 2019/06/15 17:07:27 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_fill_buff(int start, char *buffer, char *str)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(str) + start;
	while (start < len)
	{
		buffer[start] = str[i];
		start++;
		i++;
	}
}
