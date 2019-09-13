/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_buff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 10:42:42 by ramory-l          #+#    #+#             */
/*   Updated: 2019/06/15 17:07:16 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clean_buff(char *buffer, int start, int end)
{
	while (start < end)
	{
		buffer[start] = '\0';
		start++;
	}
}
