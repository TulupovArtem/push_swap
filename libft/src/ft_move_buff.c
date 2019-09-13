/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_buff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 17:33:45 by ramory-l          #+#    #+#             */
/*   Updated: 2019/06/15 17:06:22 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_move_buff(char *buffer, int offset)
{
	char	*start;
	char	*end;
	char	*ptr;
	char	temp;

	start = buffer;
	end = buffer;
	while (*end)
		end++;
	ptr = end + offset;
	while (end >= start)
	{
		temp = *end;
		*end = *ptr;
		*ptr = temp;
		ptr--;
		end--;
	}
}
