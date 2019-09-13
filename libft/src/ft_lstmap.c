/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramory-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:27:20 by ramory-l          #+#    #+#             */
/*   Updated: 2018/11/25 17:27:22 by ramory-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*current;
	t_list	*prev;

	if (!lst)
		return (NULL);
	current = ft_lstnew((f(lst))->content, (f(lst))->content_size);
	list = current;
	prev = current;
	lst = lst->next;
	while (lst)
	{
		current = ft_lstnew((f(lst))->content, (f(lst))->content_size);
		prev->next = current;
		prev = prev->next;
		lst = lst->next;
	}
	return (list);
}
