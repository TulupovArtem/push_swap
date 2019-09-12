/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 21:21:15 by idunaver          #+#    #+#             */
/*   Updated: 2019/09/12 21:21:38 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		head_table(int width)
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
	printf("|");
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