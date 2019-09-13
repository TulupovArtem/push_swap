/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_bf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramory-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 15:24:51 by ramory-l          #+#    #+#             */
/*   Updated: 2019/06/15 18:17:15 by ramory-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fill_bf(t_printf *data, t_buffer *bf)
{
	int i;
	int j;

	i = 0;
	j = data->len + bf->s;
	if (!bf->temp[0])
		return ;
	while (bf->s < j)
	{
		bf->buffer[bf->s] = bf->temp[i];
		bf->s++;
		i++;
		ft_check_buffer(data, bf);
	}
}
