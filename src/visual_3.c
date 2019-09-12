/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 21:21:15 by idunaver          #+#    #+#             */
/*   Updated: 2019/09/12 21:42:22 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	head_table_1(int width)
{
	int tmp;

	tmp = (width - 2) / 2;
	printf("\n");
	line(width);
	printf("|");
	while (tmp--)
		printf(" ");
	printf("a");
	tmp = (width - 1) / 2;
	while (tmp--)
		printf(" ");
}

static void	head_table_2(int width)
{
	int tmp;

	tmp = (width - 2) / 2;
	while (tmp--)
		printf(" ");
	printf("b");
	tmp = (width - 1) / 2;
	while (tmp--)
		printf(" ");
	printf("|\n");
	line(width);
}

void		head_table(int width)
{
	head_table_1(width);
	printf("|");
	head_table_2(width);
}
