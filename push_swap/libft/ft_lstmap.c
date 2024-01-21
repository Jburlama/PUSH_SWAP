/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:41:39 by jburlama          #+#    #+#             */
/*   Updated: 2023/10/11 23:18:28 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*ptr;
	t_list	*ptr2;

	if (lst == NULL)
		return (NULL);
	head = ft_lstnew(f(lst->content));
	if (head == NULL)
		return (NULL);
	ptr2 = head;
	ptr = lst->next;
	while (ptr)
	{
		ptr2->next = ft_lstnew(f(ptr->content));
		if (ptr2 == NULL)
		{
			del(ptr2);
			return (NULL);
		}
		ptr2 = ptr2->next;
		ptr = ptr->next;
	}
	return (head);
}
