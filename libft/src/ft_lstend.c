/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 20:56:33 by idunaver          #+#    #+#             */
/*   Updated: 2018/12/20 16:04:24 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstend(t_list *start, t_list *new)
{
	if (!start || !new)
		return (NULL);
	while (start->next)
		start = start->next;
	start->next = new;
	if (!start->next)
		return (NULL);
	return (start->next);
}
