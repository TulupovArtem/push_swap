/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 21:21:15 by idunaver          #+#    #+#             */
/*   Updated: 2019/09/13 20:38:10 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	head_table_1(int width)
{
	int tmp;

	tmp = (width - 2) / 2;
	ft_printf("\n");
	line(width);
	ft_printf("|");
	while (tmp--)
		ft_printf(" ");
	ft_printf("a");
	tmp = (width - 1) / 2;
	while (tmp--)
		ft_printf(" ");
}

static void	head_table_2(int width)
{
	int tmp;

	tmp = (width - 2) / 2;
	while (tmp--)
		ft_printf(" ");
	ft_printf("b");
	tmp = (width - 1) / 2;
	while (tmp--)
		ft_printf(" ");
	ft_printf("|\n");
	line(width);
}

void		head_table(int width)
{
	head_table_1(width);
	ft_printf("|");
	head_table_2(width);
}
