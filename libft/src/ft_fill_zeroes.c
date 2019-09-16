/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_zeroes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 10:50:35 by ramory-l          #+#    #+#             */
/*   Updated: 2019/09/16 15:50:50 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	for_mode(char *buffer, char mode, size_t size)
{
	size_t		i;

	i = 0;
	if (mode == '>')
	{
		while (buffer[i])
			i++;
		while (i < size)
		{
			buffer[i] = '0';
			i++;
		}
	}
	return ((int)i);
}

static int	back_mode(char *buffer, char mode, size_t size, int len)
{
	int		i;

	i = 0;
	if (mode == '<')
	{
		ft_move_buff(buffer, size - len);
		while (!buffer[i])
		{
			buffer[i] = '0';
			i++;
		}
	}
	return (i);
}

int			ft_fill_zeroes(char *buffer, char mode, size_t size, int len)
{
	return (for_mode(buffer, mode, size) ||
			back_mode(buffer, mode, size, len));
}
